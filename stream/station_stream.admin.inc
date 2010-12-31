<?php
// $Id: station_stream.admin.inc 246 2010-12-04 17:41:55Z cmk $

/**
 * @todo Admin setting to define track info order, default order: artist, title, album, label
 * @todo Consider time played display format, select from Drupal date formats or in the module, recommend format
 */

function station_stream_admin_settings() {
  $form = array();
  $form['station_stream_type'] = array(
    '#type' => 'select',
    '#title' => t('Server type'),
    '#default_value' => variable_get('station_stream_type', ''),
    '#options' => array(
        '' => t('select one'),
        'shoutcast' => t('SHOUTcast'),
        ),
    '#description' => t(''),
    '#required' => TRUE,
  );
  $form['station_stream_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Server URL'),
    '#default_value' => variable_get('station_stream_url', 'http://127.0.0.1'),
    '#size' => 40,
    '#maxlength' => 255,
    '#description' => t('The URL of the streaming audio server, including http:// or https://'),
    '#required' => TRUE,
  );
  $form['station_stream_port'] = array(
    '#type' => 'textfield',
    '#title' => t('Server Port'),
    '#default_value' => variable_get('station_stream_port', '8000'),
    '#size' => 4,
    '#maxlength' => 4,
    '#description' => t('Streaming server port'),
    '#required' => TRUE,
  );
  $form['station_stream_username'] = array(
    '#type' => 'textfield',
    '#title' => t('Server username'),
    '#default_value' => variable_get('station_stream_username', 'admin'),
    '#size' => 20,
    '#maxlength' => 100,
    '#description' => t('Streaming server username'),
    '#required' => TRUE,
  );
  $form['station_stream_password'] = array(
    '#type' => 'textfield',
    '#title' => t('Server password'),
    '#default_value' => variable_get('station_stream_password', ''),
    '#size' => 20,
    '#maxlength' => 100,
    '#description' => t('Streaming server password'),
    '#required' => TRUE,
  );
  $form['station_stream_cachetime'] = array(
    '#type' => 'select',
    '#title' => t('Cache Time'),
    '#default_value' => variable_get('station_stream_cachetime', 1),
    '#options' => array(0, 1, 2, 4, 5, 10, 15, 30, 60),
    '#description' => t('Minutes between stream metadata retrieval')
  );
  $form['station_stream_error_reporting'] = array(
    '#type' => 'select',
    '#title' => t('Error Reporting'),
    '#default_value' => variable_get('station_stream_error_reporting', 0),
    '#options' => array(t('Write errors to the log'), t('Write errors to the log and to the screen')),
    '#description' => t('Designate how errors should be displayed when stream metadata feed is unavaible or invalid'),
  );
  return system_settings_form($form);
}
