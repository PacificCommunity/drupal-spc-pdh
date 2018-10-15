<?php

// Implements hook_menu()
function articles_syndication_menu() {
  $items = array();

  $items['syndication/article/create'] = array(
    'page callback' => 'syndication_article_create',
    'access callback' => TRUE,
    'type' => MENU_CALLBACK,
  );

  $items['syndication/article/update'] = array(
    'page callback' => 'syndication_article_update',
    'access callback' => TRUE,
    'type' => MENU_CALLBACK,
  );

  return $items;
}


function syndication_article_create() {
  // Сhecks on required fields
  if (empty($_POST['title']) or empty($_POST['original_id'])) {
    watchdog('syndication_article', "Syndication failed. Required field is missing.");
    exit("Syndication failed. Required field is missing.");
  }

  $user_uid = 1;
  $syndicated_id = $_POST['original_id'];

  // Creates an array with parameters for node creation
  $values = array();
  $values['title'] = $_POST['title'];
  $values['body'] = $_POST['body'];
  $values['body_summary'] = $_POST['body_summary'];
  $values['image'] = !empty($_POST['image']) ? $_POST['image'] : null;
  $values['tags']= !empty($_POST['tags']) ?  explode(', ', $_POST['tags']) : null;

  $node = new stdClass();
  $node->type = 'article';
  node_object_prepare($node); 
  $node->language = LANGUAGE_NONE; 
  $node->uid = $user_uid; 
  $node->status = 1; 
  $node->promote = 0; 
  $node->comment = 0;
  $node->field_syndicated_id[LANGUAGE_NONE][] = array(
    'value' => $syndicated_id
  );

  // Creates a node with received fields
  $node = node_set_fields($node, $values);

  // Saves logs
  watchdog('syndication_article', "Node '$node->title' ($node->nid) was successfully created with data: ".print_r($values,true));
  exit("Node '$node->title' ($node->nid) was successfully created with data: ".print_r($values,true));
}


function syndication_article_update() {
  // Сhecks on required fields (for updating it's only "original_id")
  if (empty($_POST['original_id'])) {
    watchdog('syndication_article', "Syndication failed. Required field <original_id> is missing.");
    exit("Syndication failed. Required field <original_id> is missing.");
  }

  $syndicated_id = $_POST['original_id'];

  // Gets node by "original_id"
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'article')
    ->propertyCondition('status', 1)
    ->fieldCondition('field_syndicated_id', 'value', $syndicated_id, '=')
    ->addMetaData('account', user_load(1));
  $result = $query->execute();
  
  if (empty($result['node'])) {
    watchdog('syndication_article', "Syndication failed. Node with original_id=".$syndicated_id." doesn't exist.");
    exit("Syndication failed. Node with original_id=".$syndicated_id." doesn't exist.");
  }

  $nid = current($result['node'])->nid;
  $node = node_load($nid);

  // Creates an array with parameters for node creation
  $values = array();
  $values['title'] = !empty($_POST['title']) ? $_POST['title'] : $node->title;
  $values['body']= !empty($_POST['body']) ? $_POST['body'] : $node->body[LANGUAGE_NONE][0]['value'];
  $values['body_summary'] = !empty($_POST['body_summary']) ? $_POST['body_summary'] : $node->body[LANGUAGE_NONE][0]['summary'];
  $values['image'] = !empty($_POST['image']) ? $_POST['image'] : null;
  $values['tags']= !empty($_POST['tags']) ?  explode(', ', $_POST['tags']) : null;

  // Creates a node with received fields
  $node = node_set_fields($node, $values);
  
  // Saves logs
  watchdog('syndication_article', "Node '$node->title' ($node->nid) was successfully updated with data: ".print_r($values,true));
  exit("Node '$node->title' ($node->nid) was successfully updated with data: ".print_r($values,true));
}


function node_set_fields($node, $values) {
  $node->title = $values['title'];

  if (!empty($values['body']) || !empty($values['body_summary'])) {
    $body_field = array();
    array_push($body_field, array(
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
    $node->field_tags[LANGUAGE_NONE] = $tags_field;
  }
  if (!empty($values['image'])) {
    $file_image = system_retrieve_file($values['image'], 'public://pictures/', TRUE);
    $image_field = array();
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

  node_save($node);
  return $node;
}
