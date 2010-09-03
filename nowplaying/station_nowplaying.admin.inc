<?php
// $Id: station_nowplaying.admin.inc,v 1.3 2010/01/22 00:00:00 cmk Exp $

function station_nowplaying_admin_settings() {
  // Get the first web stream found to set the default shoutcast history url
  $schedules = array();
  $streams = array();
  $stream_url = '';
  $default_schedule_nid = variable_get('station_schedule_default', 0);
  $schedules = station_get_schedules($default_schedule_nid);
  $streams = $schedules[$default_schedule_nid]['streams'];
  foreach ($streams as $key => $stream) {
    foreach ($stream['urls'] as $url) {
      if (!empty($url)) {
        preg_match("/(http:\/\/.[^\/]*)/", $url, $match);
        $stream_url = $match[0];
        $schedule_title = $stream['title'];
        break;
      }
    }
    if (!isset($stream_url)) {
      break;
    }
  }

  $form = array();
  // Shoutcast settings
  $form['shoutcast'] = array(
    '#type' => 'fieldset',
    '#title' => t('Shoutcast Server Information'),
    '#collapsible' => FALSE,
    '#description' => t('Enter information about your Shoutcast server'),
 );
  $form['shoutcast']['station_nowplaying_history_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Song History URL'),
    '#default_value' => variable_get('station_nowplaying_history_url', $stream_url . '/played.html'),
    '#required' => TRUE,
    '#description' => t('The Shoutcast Song History url where recently played tracks are listed for the stream. Default ' . $stream_url . '/played.html'),
  );
  $form['shoutcast']['station_nowplaying_shoutcast_timezone'] = array(
    '#type' => 'date_timezone',
    '#default_value' => variable_get('station_nowplaying_shoutcast_timezone', variable_get('date_default_timezone', 0)),
    '#description' => "Select the timezone where your Shoutcast server is located. Change only if different than web server.",
  );
  $form['shoutcast']['station_nowplaying_cachetime'] = array(
    '#type' => 'select',
    '#title' => t('Cache Time'),
    '#default_value' => variable_get('station_nowplaying_cachetime', 1),
    '#options' => array(0, 1, 2, 4, 5, 10, 15, 30, 60),
    '#description' => t('Minutes between Shoutcast history retrieval.')
  );
  // Track-related settings
  $form['filters'] = array(
    '#type' => 'fieldset',
    '#title' => t('Track Display'),
    '#collapsible' => FALSE,
    '#description' => t('Settings to manage how tracks are displayed'),
  );
  $form['filters']['station_nowplaying_filters'] = array(
    '#type' => 'textfield',
    '#title' => t('Song Filters'),
    '#default_value' => variable_get('station_nowplaying_filters', ''),
    '#description' => t('Remove tracks whose titles match or contain these values, separate values with semicolons.'),
  );
  // Block settings
  $form['block'] = array(
    '#type' => 'fieldset',
    '#title' => t('Block Display'),
    '#collapsible' => FALSE,
    '#description' => t('Settings to manage the recently played block'),
  );
  $form['block']['station_nowplaying_block_limit'] = array(
    '#type' => 'textfield',
    '#title' => t('Number of Tracks'),
    '#default_value' => variable_get('station_nowplaying_block_limit', 6),
    '#size' => 2,
    '#maxlength' => 2,
    '#description' => t('The format to display track date/time played.'),
    '#required' => TRUE,
  );
  $form['block']['station_nowplaying_block_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Block Title'),
    '#default_value' => variable_get('station_nowplaying_block_subject', t('Recently Played')),
    '#size' => 32,
    '#maxlength' => 32,
    '#description' => t('The title of the recently played block.'),
    '#required' => TRUE,
  );
  $form['block']['station_nowplaying_block_display_fields'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Display Fields'),
    '#default_value' => variable_get('station_nowplaying_block_display_fields', array(
        'datetime',
        'artist',
        'song',
      )
    ),
    '#options' => array(
        'datetime' => t('Date/Time Played'),
        'artist' => t('Artist'),
        'song' => t('Song'),
        'album' => t('Album'),
        'label' => t('Label'),
    ),
  );
  $form['block']['station_nowplaying_block_dateformat'] = array(
    '#type' => 'textfield',
    '#title' => t('Date/Time Format'),
    '#default_value' => variable_get('station_nowplaying_block_dateformat', 'h:i'),
    '#size' => 16,
    '#maxlength' => 16,
    '#description' => t('The format to display track date/time played.'),
    '#required' => TRUE,
  );
  // Page settings
  $form['page'] = array(
    '#type' => 'fieldset',
    '#title' => t('Page Display'),
    '#collapsible' => FALSE,
    '#description' => t('Settings to manage the recently played page'),
  );
  $form['page']['station_nowplaying_page_limit'] = array(
    '#type' => 'textfield',
    '#title' => t('Number of Tracks'),
    '#default_value' => variable_get('station_nowplaying_page_limit', 20),
    '#size' => 2,
    '#maxlength' => 2,
    '#description' => t('The format to display track date/time played.'),
    '#required' => TRUE,
  );
  $form['page']['station_nowplaying_page_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Block Title'),
    '#default_value' => variable_get('station_nowplaying_page_subject', t('Recently Played')),
    '#size' => 32,
    '#maxlength' => 32,
    '#description' => t('The title of the recently played page.'),
    '#required' => TRUE,
  );
  $form['page']['station_nowplaying_page_display_fields'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Display Fields'),
    '#default_value' => variable_get('station_nowplaying_page_display_fields', array(
        'datetime',
        'artist',
        'song',
        'album',
        'label',
      )
    ),
    '#options' => array(
        'datetime' => t('Date/Time Played'),
        'artist' => t('Artist'),
        'song' => t('Song'),
        'album' => t('Album'),
        'label' => t('Label'),
    ),
  );
  $form['page']['station_nowplaying_page_dateformat'] = array(
    '#type' => 'textfield',
    '#title' => t('Date/Time Format'),
    '#default_value' => variable_get('station_nowplaying_page_dateformat', 'h:i'),
    '#size' => 16,
    '#maxlength' => 16,
    '#description' => t('The format to display track date/time played.'),
    '#required' => TRUE,
  );
  return system_settings_form($form);
}
