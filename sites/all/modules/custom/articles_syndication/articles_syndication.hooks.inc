<?php

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
  //Make not hardcoded
  $user_uid = 1;

  $title = $_POST['title'];
  $body = $_POST['body'];
  $body_summary = $_POST['body_summary'];
  $image = !empty($_POST['image']) ? $_POST['image'] : null;
  $tags = !empty($_POST['tags']) ?  explode(', ', $_POST['tags']) : null;

  $node = new stdClass();
  $node->title = $title;
  $node->body[LANGUAGE_NONE][] = array(
    'value' => $body,
    'summary' => $body_summary
  );
  $node->type = 'article';
  node_object_prepare($node); 
  $node->language = LANGUAGE_NONE; 
  $node->uid = $user_uid; 
  $node->status = 1; 
  $node->promote = 0; 
  $node->comment = 0; 

  if (!empty($tags)) {
    $vocab = taxonomy_vocabulary_machine_name_load('tags');
    $vid = $vocab->vid;

    foreach ($tags as $tag) {
      $term = new stdClass();
      $term->name = $tag;
      $term->vid = $vid;

      $existing_term = taxonomy_get_term_by_name($tag);

      if (empty($existing_term)) {
        taxonomy_term_save($term);
        $node->field_tags[LANGUAGE_NONE][] = array(
          'tid' => $term->tid
        );
      } else {
        $node->field_tags[LANGUAGE_NONE][] = array(
          'tid' => current($existing_term)->tid
        );
      }
    }
  }

  if (!empty($image)) {
    $file_image = system_retrieve_file($image, 'public://pictures/', TRUE);

    $node->field_image[LANGUAGE_NONE][] = array(
      'fid' => $file_image->fid,
      'uid' => $file_image->uid,
      'uri' => $file_image->uri,
      'filename' => $file_image->filename,
      'filemime' => $file_image->filemime,
      'status' => $file_image->status
    );
  }

  node_save($node);  
  exit();
}

function syndication_article_update() {
  var_dump($_POST);
}
