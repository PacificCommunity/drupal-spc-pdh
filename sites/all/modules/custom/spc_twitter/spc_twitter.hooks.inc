<?php

$libraries = libraries_get_libraries();
if (isset($libraries['twitteroauth'])) {
  $twitteroauth = $libraries['twitteroauth'];
}
require_once $twitteroauth.'/autoload.php';

use Abraham\TwitterOAuth\TwitterOAuth;

/**
 * Implements hook_theme().
 */

function spc_twitter_theme($existing, $type, $theme, $path)
{
  if($type == 'module')
  {
    return [
      'spc_tweet_item' => [
        'variables' => array('tweet_item'=>1),
        'template' => 'spc_tweet_item'
      ]
    ];
  }
  return [];
}

/**
 * Implements hook_block_info().
 */

function spc_twitter_block_info() {
  $blocks['spc_twitter_topic_tweets'] = [
    'info' => t('SPC Twitter Topic Tweets')
  ];
  return $blocks;
}



/**
* Implements hook_menu().
*/
function spc_twitter_menu() {
	$items['admin/config/administration/tw_ac_configuration'] = array(
	'title' => 'Twitter Account configuration',
	'page callback' => 'drupal_get_form',
	'page arguments' => array('spc_twitter_tw_ac_configuration_form'),
	'access arguments' => array('administer users'),
	'type' => MENU_NORMAL_ITEM,
	);

	return $items;
}


/**
 * Admin form to configurable welcome message
 */
function spc_twitter_tw_ac_configuration_form($form, &$form_state) {
  $form['tw_consumer_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Twitter Consumer Key'),
    '#required' => TRUE,
    '#default_value' => variable_get('tw_consumer_key', '')
  );
  $form['tw_consumer_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('Twitter Consumer Secret'),
    '#required' => TRUE,
    '#default_value' => variable_get('tw_consumer_secret', '')
  );
  $form['tw_access_token'] = array(
    '#type' => 'textfield',
    '#title' => t('Twitter Access Token'),
    '#required' => TRUE,
    '#default_value' => variable_get('tw_access_token', '')
  );
  $form['tw_access_token_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('Twitter Access Token Secret'),
    '#required' => TRUE,
    '#default_value' => variable_get('tw_access_token_secret', '')
  );
  $form['tw_items_limit'] = array(
    '#type' => 'textfield',
    '#title' => t('Twitter Items Limit'),
    '#default_value' => variable_get('tw_items_limit', '')
  );
 
  return system_settings_form($form);
}

function _spc_tweet_mapper($tweet) {
	if ($tweet) {
		$timestmp = strtotime($tweet->created_at);
	    return [
			'id' => $tweet->id_str,
			'created_at' => $tweet->created_at,
			'timestamp' => $timestmp,
	    ];
	}
	return array();
}


function spc_twitter_block_view($delta = '') {
  $block = array();
  switch ($delta) {
    case 'spc_twitter_topic_tweets':
    	$current_node = menu_get_object();
		$twitter_users = array('link_digital', 'spc_cps');
    	if ($current_node && $current_node->type == 'thematic_group') {
    		if ($current_node->field_show_tweets && $current_node->field_show_tweets['und'][0]['value'] && $current_node->field_twitter_account_names) {
    			$screen_names = $current_node->field_twitter_account_names;
	    		$cache_name = 'cache_topic_' . $current_node->vid;
		    	if ($cached = cache_get($cache_name, 'cache')) {
		    		$tweets = $cached->data;
		    	}
		    	if (empty($tweets)) {
		    		$tw_consumer_key = variable_get('tw_consumer_key', '');
					$tw_consumer_secret = variable_get('tw_consumer_secret', '');
					$tw_access_token = variable_get('tw_access_token', '');
					$tw_access_token_secret = variable_get('tw_access_token_secret', '');
					$tw_limit = variable_get('tw_items_limit', 10);
					if (!$tw_limit) {
						$tw_limit = 10;
					} 
		    		$tweets = array();
		    		if ($tw_consumer_key && $tw_consumer_secret && $tw_access_token && $tw_access_token_secret && $tw_limit) {
				    	$connection = new TwitterOAuth($tw_consumer_key, $tw_consumer_secret, $tw_access_token, $tw_access_token_secret);
				    	foreach ($screen_names['und'] as $key => $name) {
				    		$data = $connection->get("statuses/user_timeline", ["count" => $tw_limit, "exclude_replies" => true, "screen_name" => $name['value'], "source" => "web", "include_rts" => false]);
				    		if (isset($data->errors)) {
				    			watchdog('spc_twitter_connection_error', '<pre>' . print_r($data->errors, TRUE) . '</pre>');				    			
				    		}
				    		else {
					    		foreach ($data as &$item) {
						    		$item = _spc_tweet_mapper($item);
						    		$tweets[] = $item;
						    	}
				    		}
				    	}
						function cmp($a, $b) {
						    if ($a['timestamp'] == $b['timestamp']) {
						        return 0;
						    }
						    return ($a['timestamp'] < $b['timestamp']) ? -1 : 1;
						}
						if ($tweets) {
							usort($tweets, "cmp");
							$tweets = array_slice(array_reverse($tweets), 0, $tw_limit);
							foreach ($tweets as &$tweet) {
				    			$updated_tweet = $connection->get("statuses/oembed", ["url" => "https://twitter.com/Interior/status/" . $tweet['id'], "omit_script" => true, "hide_thread" => true]);
				    			$tweet = $updated_tweet;
							}

					    	cache_set($cache_name, $tweets, 'cache', time() + 60*60);
						}
		    		}
		    	}
		    	if ($tweets) {
					foreach ($tweets as &$item) {
						$item = theme('spc_tweet_item', ['tweet_item'=>$item]);
					}

					$block['subject'] = t('Latest Tweets');
					$block['content'] = "<div class=list-tweets>" .implode('', $tweets) . "</div>";
		    	}
    		}
    	}
	}
  return $block;
}
