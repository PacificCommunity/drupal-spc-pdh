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
		    'name' => $tweet->user->name,
			'screen_name' => $tweet->user->screen_name,
			'profile_image_url' => $tweet->user->profile_image_url,
			'text' => $tweet->full_text,
			'created_at' => $tweet->created_at,
			'timestamp' => $timestmp,
			'urls' => $tweet->entities->urls ? property_exists($tweet->entities, 'urls') : array(),
			'media' => $tweet->entities->media ? property_exists($tweet->entities, 'media') : array(),
			'hashtags' => $tweet->entities->hashtags ? property_exists($tweet->entities, 'hashtags') : array(),
			'user_mentions' => $tweet->entities->user_mentions ? property_exists($tweet->entities, 'user_mentions') : array() 
	    ];
	}
	return array();
}

function _spc_tweet_how_long_ago($timestmp) {
	$ago = false;
	$elapsed = time() - $timestmp;
	if ($elapsed < 60) {
		$ago = $elapsed . 's';
	} else if ($elapsed < 3600) {
		$ago = round($elapsed / 60) . 'm';
	} else if ($elapsed < 86400) {
		$ago = round($elapsed / 3600) . 'h';
	}
	else if ($elapsed > 86400) {
		$ago = date('D j M', $timestmp);
	}
	return $ago;
}

function _spc_tweet_parse_text($tweet) {
	$item = $tweet;
	// var_dump($item['urls']);
	if (array_key_exists('urls', $item) && $item['urls']) {
		// var_dump(3333354);
		// var_dump($item['urls']);
	    foreach ($item['urls'] as $key => $value) {
	    	var_dump($value->expanded_url);
	    	echo "<hr>";
	    	$replace = "<a href='".$value->expanded_url."' target='_blank'>". $value->display_url ."</a>";
	    	$item['text'] = str_replace($value->url, $replace, $item['text']);
	    }
	}
	// if (array_key_exists('media', $item) && $item['media']) {
	//     foreach ($item['media'] as $key => $value) {
	//     	var_dump($item['media']);
	//     	var_dump(444444444444444444444444444);
	//     	$replace = "<a href='".$value->url."' target='_blank'><img class='media-image' src='". $value->media_url_https ."'></img></a>";
	//     	$item['text'] = str_replace($value->url, $replace, $item['text']);
	//     }
	// }
	// if (array_key_exists('hashtags', $item) && $item['hashtags']) {
	//     foreach ($item['hashtags'] as $key => $value) {
	//     	var_dump($item['hashtags']);
	//     	var_dump(222222222222222222222);
	//     	$replace = "<a href='https://twitter.com/hashtag/".$value->text."?src=hash' target='_blank'>#". $value->text ."</a>";
	//     	$item['text'] = str_replace('#' . $value->text, $replace, $item['text']);
	//     }
	// }
 //    if (array_key_exists('user_mentions', $item) && $item['user_mentions']) {
	//     foreach ($item['user_mentions'] as $key => $value) {
	//     	var_dump($item['user_mentions']);
	//     	var_dump(1111111111111111111111111);
	//     	$replace = "<a href='https://twitter.com/".$value->screen_name."' target='_blank'>@". $value->screen_name ."</a>";
	//     	$item['text'] = str_replace('@'. $value->screen_name, $replace, $item['text']);
	//     }
	// }
 	return $item['text'];
}

function spc_twitter_block_view($delta = '') {
  $block = array();
  switch ($delta) {
    case 'spc_twitter_topic_tweets':
    	$current_node = menu_get_object();
		$twitter_users = array('link_digital', 'spc_cps');
    	if ($current_node && $current_node->type == 'thematic_group') {
    		if ($current_node->field_show_tweets['und'][0]['value'] && $current_node->field_twitter_account_names) {
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
		    		$tweets = array();
		    		if ($tw_consumer_key && $tw_consumer_secret && $tw_access_token && $tw_access_token_secret && $tw_limit) {
				    	$connection = new TwitterOAuth($tw_consumer_key, $tw_consumer_secret, $tw_access_token, $tw_access_token_secret);
				    	echo "<hr>";
				    	foreach ($screen_names['und'] as $key => $name) {
				    		$data = $connection->get("statuses/user_timeline", ["count" => $tw_limit, "exclude_replies" => true, "screen_name" => $name['value'], "source" => "web", "tweet_mode" => "extended"]);
				    		if ($data->errors) {
				    			watchdog('spc_twitter_connection_error', '<pre>' . print_r($data->errors, TRUE) . '</pre>');				    			
				    		}
				    		else {
					    		foreach ($data as &$item) {
					    			var_dump($item);
					    			dsm($item);
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
					    	cache_set($cache_name, $tweets, 'cache', time() + 60*60);
						}
		    		}
		    	}
		    	if ($tweets) {
					foreach ($tweets as &$item) {
					    $item['text'] = _spc_tweet_parse_text($item);

					    $item['time_ago'] = _spc_tweet_how_long_ago($item['timestamp']);
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
