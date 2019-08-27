<?php
/*
  Preprocess
*/


function spc_preprocess_html(&$vars) {
  //  kpr($vars['content']);
}

function spc_preprocess_page(&$vars,$hook) {
  //typekit
  //drupal_add_js('http://use.typekit.com/XXX.js', 'external');
  //drupal_add_js('try{Typekit.load();}catch(e){}', array('type' => 'inline'));

  //webfont
  //drupal_add_css('http://cloud.webtype.com/css/CXXXX.css','external');

  //googlefont
  //  drupal_add_css('http://fonts.googleapis.com/css?family=Bree+Serif','external');

  // If this is a panel page, add template suggestions.
  // Must have Ctools Page Manager enabled. Uncomment to use.
  if (module_exists('page_manager')) {
    if($panel_page = page_manager_get_current_page()) {
      // add a generic suggestion for all panel pages
      $vars['theme_hook_suggestions'][] = 'page__panel';

      // add the panel page machine name to the template suggestions
      $vars['theme_hook_suggestions'][] = 'page__' . $panel_page['name'];

      //add a body class for good measure
      $body_classes[] = 'page-panel';
    }
  }
}

function spc_preprocess_region(&$vars,$hook) {
  //  kpr($vars['content']);
}

function spc_preprocess_block(&$vars, $hook) {
  //  kpr($vars['content']);

  //lets look for unique block in a region $region-$blockcreator-$delta
   $block =
   $vars['elements']['#block']->region .'-'.
   $vars['elements']['#block']->module .'-'.
   $vars['elements']['#block']->delta;

  // print $block .' ';
   switch ($block) {
     case 'header-menu_block-2':
       $vars['classes_array'][] = '';
       break;
     case 'sidebar-system-navigation':
       $vars['classes_array'][] = '';
       break;
    default:

    break;

   }


  switch ($vars['elements']['#block']->region) {
    case 'header':
      $vars['classes_array'][] = '';
      break;
    case 'sidebar':
      $vars['classes_array'][] = '';
      $vars['classes_array'][] = '';
      break;
    default:

      break;
  }

}

function spc_preprocess_node(&$vars,$hook) {
  //  kpr($vars['content']);
}

function spc_preprocess_comment(&$vars,$hook) {
  //  kpr($vars['content']);
}

function spc_preprocess_field(&$vars,$hook) {
  //  kpr($vars['content']);
  //add class to a specific field
  switch ($vars['element']['#field_name']) {
    case 'field_ROCK':
      $vars['classes_array'][] = 'classname1';
    case 'field_ROLL':
      $vars['classes_array'][] = 'classname1';
      $vars['classes_array'][] = 'classname2';
      $vars['classes_array'][] = 'classname1';
    case 'field_FOO':
      $vars['classes_array'][] = 'classname1';
    case 'field_BAR':
      $vars['classes_array'][] = 'classname1';
    default:
      break;
  }

  if ($vars['element']['#field_name'] == 'field_dsp_datasets') {
    $datasets_names = !empty($vars['element']['#items']) ? $vars['element']['#items'] : [];
    $names = array();
    foreach ($datasets_names as $id => $item) {
      $names[] = $item['value'];
    }
    $names_str = '('.join(' OR ', $names).')';

    $params = array(
      'fq' => 'name:'.$names_str
    );
    try {
      $client = govcms_ckan_client();
      $resp = $client->get('action/package_search', $params);
    }
    catch (Exception $e) {
      watchdog_exception('dashboard_secondary_page', $e);
    }

    $datasets_info = $resp->data->results;
    $vars['element']['datasets_info'] = $datasets_info;
  }

  if ($vars['element']['#bundle'] == 'field_dsp_targets' && $vars['element']['#field_name'] == 'field_title') {
    $target_title = $vars['element']['#items'][0]['value'];
    $vars['items'][0]['#prefix'] = '<span id="'.drupal_html_class($target_title).'">';
    $vars['items'][0]['#suffix'] = '</span>';
  }
}

function spc_preprocess_maintenance_page(){
  //  kpr($vars['content']);
}

/**
 * Implements hook_form_alter().
 */
function spc_form_ckan_search_form_alter(&$form, &$form_state, $form_id) {
  $node = menu_get_object();
  $id = _ckan_tweaks_get_thematic_area_from_node($node);
  if ($id) {
    $form['thematic_area'] = [
      '#type' => 'hidden',
      '#value' => $id
    ];

    $form['search_type_container'] = array(
      '#type' => 'container',
      '#attributes' => array('class' => array('search-type-container'))
    );
    $form['search_type_container']['search_type'] = [
      '#type' => 'select',
      '#default_value' => 'dataset',
      '#options' => [
        'article' => t('Story'),
        'dataset' => t('Dataset')
      ],
      '#required' => TRUE,
    ];

    // Put submit after newly added fields
    $form['submit']['#weight'] = 10;
  }
}


/**
 * Implements hook_theme().
 */
function spc_theme($existing, $type, $theme, $path)
{
  if($type == 'module')
  {
    return [
      'spc_two_66_33' => [
        'template' => 'spc-two-66-33',
        'render element' => 'content',
      ]
    ];
  }
  return [];
}

function spc_preprocess_entity(&$variables) {
  if (isset($variables['entity_type'])) {
    $entity_type = $variables['entity_type'];
    if (in_array($entity_type, array('bean'))) {
      $entity = $variables['bean'];
      $path = current_path();
      $patterns = array(
        'search/articles',
        'search/arcticles/*',
        'search/articles/*/*'
      );
      $search_title = '<strong>' . t('Search stories') . '</strong>';
      if (drupal_match_path($path, implode("\n", $patterns))) {
        $term = arg(2);
        $thematic_area = arg(3);
        if (!empty($term)) {
          $search_title .= ' by ' . check_plain($term);
        }
        if (!empty($thematic_area)) {
          $search_title .= ' & ' . check_plain($thematic_area);
        }
        if (isset($variables['content']['field_title_bg'][0]['#markup'])) {
          $variables['content']['field_title_bg'][0]['#markup'] = '<h1>' . $search_title . '</h1>';
        }
      }

      if (drupal_match_path($path, 'stories/by-topic/*')) {
        $thematic_area_nid = arg(2);
        if (!empty($thematic_area_nid)) {
          $thematic_area_node = node_load(arg(2));
          $search_title .= ' by ' . check_plain($thematic_area_node->title);
        }
        if (isset($variables['content']['field_title_bg'][0]['#markup'])) {
          $variables['content']['field_title_bg'][0]['#markup'] = '<h1>' . $search_title . '</h1>';
        }
      }
    }
  }
}

/**
 * Implements template_preprocess_views_view_fields
 * Defines header and content for accordion items
 */
function spc_preprocess_views_view_fields(&$vars) {
  if ($vars['view']->name == 'master_results_framework') {
    $fields_to_print = 4;
    $vars['row_header'] = '';
    $vars['row_content'] = '';
    $vars['row_label'] = '';
    foreach ($vars['fields'] as $field) {
      // Select 5 first fields for row header according to design.
      if ($fields_to_print > 0) {
        $vars['row_label'] .= $field->label_html;
        $vars['row_header'] .= $field->content;
      }
      else {
        $vars['row_content'] .= '<div class="field">' . $field->label_html;
        $vars['row_content'] .= $field->content . '</div>';
      }
      $fields_to_print--;
    }
    $vars['row_header'] .= '<div class="field-content arrow"><span class="icon"></span></div>';
    $vars['row_label'] .= '<span class="header-empty"></span>';
  }
  
  if ($vars['view']->name == 'data_insights_promoted'){
    $preview = $vars['fields']['field_data_insights_preview']->content;
    
    $img_pos = strpos($preview, '<img');
    if ($img_pos !== false){
      $new_preview = substr_replace($preview, 'class="lazy-load"', $img_pos + 5, 0);
      $vars['fields']['field_data_insights_preview']->content = $new_preview;
    }
    
    $iframe_pos = strpos($preview, '<iframe');
    if ($iframe_pos !== false){
      $new_preview = substr_replace($preview, 'class="lazy-load"', $iframe_pos + 8, 0);
      $vars['fields']['field_data_insights_preview']->content = $new_preview;
    }
    
  }
}

function spc_preprocess_views_view_unformatted(&$vars){
  if ($vars['view']->name == 'data_insights_list_page'){
    $rows = $vars['rows'];
    
    foreach($rows as $key => $row){
      $img_pos = strpos($row, '<img');
      if ($img_pos !== false){
        
        $pattern = '(src=".+")';
        preg_match($pattern, $row, $matches);
        $row = preg_replace($pattern, 'src=""', $row);
        
        $src = explode('=', $matches[0]);
        $lazy = 'class="lazy-load"' . ' data-src=' . $src[1];
        $new_preview = substr_replace($row, $lazy, $img_pos + 5, 0);
        
        $vars['rows'][$key] = $new_preview;        
      }

      $iframe_pos = strpos($row, '<iframe');
      if ($iframe_pos !== false){
        
        $pattern = '(src=".+" )';
        preg_match($pattern, $row, $matches);
        $row = preg_replace($pattern, 'src=""', $row);
        
        $src = explode('=', $matches[0]);
        $lazy = 'class="lazy-load"' . ' data-src=' . $src[1]; 
        
        $new_preview = substr_replace($row, $lazy, $iframe_pos + 8, 0);
        $vars['rows'][$key] = $new_preview;
      }   
    }
  }
}

/**
 * Implements hook_form_alter
 * Sets labels instead default values for Master results filters.
 */
function spc_form_alter(&$form, &$form_state, $form_id) {
  // Define all needed forms.
  $ids = [
    'views-exposed-form-master-results-framework-accordion-block',
    'views-exposed-form-master-results-framework-page',
  ];
  if (in_array($form['#id'], $ids)) {
    foreach ($form["#info"] as $key => $item) {
      $form[$item['value']]['#options']['All'] = $form["#info"][$key]["label"];
      $form["#info"][$key]["label"] = '';
    }
  }
}


$block = module_invoke('views', 'block_view', 'sidebar-article_ad');
print render($block);
