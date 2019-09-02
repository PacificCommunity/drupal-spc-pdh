<?php

// Implements hook_menu()
function articles_syndication_menu() {
  $items = array();

  $items['syndication/article_syndicate'] = array(
    'page callback' => 'article_syndicate',
    'access callback' => TRUE,
    'type' => MENU_CALLBACK,
  );

  return $items;
}

function article_syndicate() {
  $access = check_access();
  if (!$access[0]) {
    return drupal_json_output(array('code'=> 403, 'message' => $access[1]));
  }

  $syndicated_id = $_POST['original_id'];

  // Gets node by "original_id"
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'article')
    ->fieldCondition('field_syndicated_id', 'value', $syndicated_id, '=')
    ->addMetaData('account', user_load(1));
  $result = $query->execute();
  
  if (empty($result['node'])) {
    syndication_article_create();
  } else {
    syndication_article_update(current($result['node'])->nid);
  }
}


function check_access() {
  if (!empty($_POST['access_key'])) {
    $hash = $_POST['access_key'];
    $spass = variable_get('synpass');
    if (!password_verify($spass, $hash)) {
      watchdog('syndication_article', "Access denied. 'access_key' field is incorrect.");
      return array(false, "Access denied. 'access_key' field is incorrect.");
    } else {
      return array(true);
    }
  } else {
    watchdog('syndication_article', "Access denied. 'access_key' field is missing.");
    return array(false, "Access denied. 'access_key' field is missing.");
  }
}


function syndication_article_author() {
  $author_uid = variable_get('syndicated_author_uid');
  if (empty($author_uid)) {
    $default_name = 'SPC';
    $default_email = 'spcsyndication@linkdigital.com.au';
    $author = user_load_by_name($default_name);
    if ($author) {
      $author_uid = $author->uid;
    }
    else {
      $author_data = array(
        'name' => $default_name,
        'mail' => $default_email,
        'pass' => user_password(),
        'status' => 1,
        'roles' => array(),
      );
      $author = user_save(NULL, $author_data);
      $author_uid = $author->uid;
    }
    variable_set('syndicated_author_uid', $author_uid);
  }
  return $author_uid;
}

function syndication_article_create() {
  // Сhecks on required fields
  if (empty($_POST['title']) or empty($_POST['original_id'])) {
    watchdog('syndication_article', "Syndication failed. Required field is missing.");
    return drupal_json_output(array('code'=> 400, 'message' => "Syndication failed. Required field is missing."));
  }
  $user_uid = 1;
  $syndicated_id = $_POST['original_id'];

  // Creates an array with parameters for node creation
  $values = array();
  $values['title'] = !empty($_POST['title']) ? $_POST['title'] : null;
  $values['body'] = !empty($_POST['body']) ? $_POST['body'] : null;
  $values['body_summary'] = !empty($_POST['body_summary']) ? $_POST['body_summary'] : null;
  $values['image'] = !empty($_POST['image']) ? $_POST['image'] : null;
  $values['tags']= !empty($_POST['tags']) ?  explode(', ', $_POST['tags']) : null;


  $values['uid'] = syndication_article_author();


  $node = new stdClass();
  $node->type = 'article';
  node_object_prepare($node); 
  $node->language = LANGUAGE_NONE; 
  $node->uid = $user_uid; 
  $node->status = 0; 
  $node->promote = 0; 
  $node->comment = 0;
  $node->field_syndicated_id[LANGUAGE_NONE][] = array(
    'value' => $syndicated_id
  );

  // Creates a node with received fields
  $node = node_set_fields($node, $values);
  
  $message = "Node '$node->title' ($node->nid) was successfully created with data: ".print_r($values,true);
  
  if (variable_get('syndication_email')){
    $email = variable_get('syndication_email');
  } else {
    $email = 'datahub@spc.int';
  }

  // Send the email.
  $params = array(
    'subject' => t('Syndicated Article - created'),
    'body' => check_markup(
      t($message),
      'plain_text'
    ),
  );
  drupal_mail('articles_syndication', 'syndicated_article_created', $email, language_default(), $params);

  // Saves logs
  watchdog('syndication_article', "Node '$node->title' ($node->nid) was successfully created with data: ".print_r($values,true));
  return drupal_json_output(array('code'=> 200, 'message' => "Node '$node->title' ($node->nid) was successfully created with data: ".print_r($values,true)));
}


function syndication_article_update($nid) {
  // Сhecks on required fields (for updating it's only "original_id")
  if (empty($_POST['original_id'])) {
    watchdog('syndication_article', "Syndication failed. Required field 'original_id' is missing.");
    return drupal_json_output(array('code'=> 400, 'message' => "Syndication failed. Required field 'original_id' is missing."));
  }

  $syndicated_id = $_POST['original_id'];
  $node = node_load($nid);

  // Creates an array with parameters for node creation
  $values = array();
  $values['title'] = !empty($_POST['title']) ? $_POST['title'] : $node->title;
  $values['body']= !empty($_POST['body']) ? $_POST['body'] : $node->body[LANGUAGE_NONE][0]['value'];
  $values['body_summary'] = !empty($_POST['body_summary']) ? $_POST['body_summary'] : $node->body[LANGUAGE_NONE][0]['summary'];
  $values['image'] = !empty($_POST['image']) ? $_POST['image'] : null;
  $values['tags']= !empty($_POST['tags']) ?  explode(', ', $_POST['tags']) : null;


  $values['uid'] = syndication_article_author();

  // Creates a node with received fields
  $node = node_set_fields($node, $values);
  
  // Saves logs
  watchdog('syndication_article', "Node '$node->title' ($node->nid) was successfully updated with data: ".print_r($values,true));
  return drupal_json_output(array('code'=> 200, 'message' => "Node '$node->title' ($node->nid) was successfully updated with data: ".print_r($values,true)));
}


function node_set_fields($node, $values) {
  $node->title = $values['title'];
  if (!empty($values['uid'])) {
    $node->uid = $values['uid'];
  }
  if (!empty($values['body']) || !empty($values['body_summary'])) {
    $body_field = array();
    array_push($body_field, array(
      'format' => 'filtered_html',
      'value' => $values['body'],
      'summary' => $values['body_summary']
    ));
    $node->body[LANGUAGE_NONE] = $body_field; 
  }
  if (!empty($values['tags'])) {
    $vocab = taxonomy_vocabulary_machine_name_load('tags');
    $vid = $vocab->vid;
    $tags_field = array();

    foreach ($values['tags'] as $tag) {
      $term = new stdClass();
      $term->name = $tag;
      $term->vid = $vid;

      $existing_term = taxonomy_get_term_by_name($tag);
      if (empty($existing_term)) {
        taxonomy_term_save($term);
        array_push($tags_field, array(
          'tid' => $term->tid
        ));
      } else {
        array_push($tags_field, array(
          'tid' => current($existing_term)->tid
        ));
      }
    };
    
    $attached_tags = $node->field_tags[LANGUAGE_NONE];

    foreach ($tags_field as $f_teg){
       if (!in_array($f_teg, $attached_tags)){
         $attached_tags[] = $f_teg;
       }
    }

    $node->field_tags[LANGUAGE_NONE] = $attached_tags;
  }
  if (!empty($values['image'])) {
    $file_image = system_retrieve_file($values['image'], 'public://pictures/', TRUE);
    $image_field = array();
    if (!empty($file_image )) {
      array_push($image_field, array(
        'fid' => $file_image->fid,
        'uid' => $file_image->uid,
        'uri' => $file_image->uri,
        'filename' => $file_image->filename,
        'filemime' => $file_image->filemime,
        'status' => $file_image->status
      ));
      $node->field_image[LANGUAGE_NONE] = $image_field;
    }
  };

  node_save($node);
  return $node;
}

function articles_syndication_entity_info_alter(&$entity_info) {
  if (isset($entity_info['node']['bundles']['article'])) {
    $entity_info['node']['bundles']['article']['uri callback'] = 'articles_syndication_article_uri';
  }
}

function articles_syndication_article_uri($node) {
  if (isset($node->field_syndicated_id)) {
    $wrapper = entity_metadata_wrapper('node', $node);
    $syndicated_id = $wrapper->field_syndicated_id->raw();
    $syndicated_base_url = variable_get('syndicated_base_url');
    if (!empty($syndicated_base_url) && !empty($syndicated_id)) {    
      return array(
        'path' => $syndicated_base_url . '/node/' . $syndicated_id,
        'options' => array(
          'attributes' => array(
            'target' => '_blank'
          ),
          'absolute' => TRUE
        )
      );
    }
  }
  return array(
    'path' => 'node/' . $node->nid,
  );
}

/**
 * Implements hook_mail for module_name.
 */
function articles_syndication_mail($key, &$message, $params) {
  switch ($key) {
    case 'syndicated_article_created':
      $message['subject'] = $params['subject'];
      $message['body'][] = $params['body'];
      break;
  }
}
