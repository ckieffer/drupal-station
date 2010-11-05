<?php
// $Id: station_log.admin.inc 231 2010-11-05 05:24:11Z cmk $

/**
 * @todo Admin setting to define track info order, default order: artist, title, album, label
 * @todo Consider time played display format, select from Drupal date formats or in the module, recommend format
 */

function station_log_admin_settings() {
  $form = array();
  // Block settings
  $form['block'] = array(
    '#type' => 'fieldset',
    '#title' => t('Recently Played Block'),
    '#collapsible' => FALSE,
    '#description' => t('Show recently played songs/artists in a block. Use admin/blocks to enable, position, and set a title.'),
  );
  $form['block']['station_log_block_limit'] = array(
    '#type' => 'textfield',
    '#title' => t('Track Count'),
    '#default_value' => variable_get('station_log_block_limit', 5),
    '#size' => 2,
    '#maxlength' => 2,
    '#description' => t('The number of songs to display'),
    '#required' => TRUE,
  );
  $form['block']['station_log_block_display_fields'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Track Info'),
    '#default_value' => variable_get('station_log_block_display_fields', array(
      )
    ),
    '#options' => array(
        'datetime' => t('Date/Time Played'),
        'album' => t('Album'),
        'label' => t('Label'),
    ),
    '#description' => t('Show these fields in addition to artist and song title'),
  );
  $form['block']['station_log_block_dateformat'] = array(
    '#type' => 'textfield',
    '#title' => t('Date/Time Format'),
    '#default_value' => variable_get('station_log_block_dateformat', 'h:i'),
    '#size' => 16,
    '#maxlength' => 16,
    '#description' => t('Played date/time format, uses PHP date() formats'),
  );
  // Page settings
  $form['page'] = array(
    '#type' => 'fieldset',
    '#title' => t('Recently Played Page'),
    '#collapsible' => FALSE,
    '#description' => t('Configure the recently played page.'),
  );
  $form['page']['station_log_page_limit'] = array(
    '#type' => 'textfield',
    '#title' => t('Hours to Show'),
    '#default_value' => variable_get('station_log_page_limit', 6),
    '#size' => 2,
    '#maxlength' => 2,
    '#description' => t('The number of recent hours of songs to display'),
    '#required' => TRUE,
  );
  $form['page']['station_log_page_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Page Title'),
    '#default_value' => variable_get('station_log_page_subject', t('Recently Played')),
    '#size' => 32,
    '#maxlength' => 32,
    '#description' => t('The title of the recently played page'),
    '#required' => TRUE,
  );
  $form['page']['station_log_page_display_fields'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Track Info'),
    '#default_value' => variable_get('station_log_page_display_fields', array(
        'datetime',
        'album',
        'label',
      )
    ),
    '#options' => array(
        'datetime' => t('Date/Time Played'),
        'album' => t('Album'),
        'label' => t('Label'),
    ),
    '#description' => t('Show these fields in addition to artist and song title'),
  );
  $form['page']['station_log_page_dateformat'] = array(
    '#type' => 'textfield',
    '#title' => t('Date/Time Format'),
    '#default_value' => variable_get('station_log_page_dateformat', 'h:i'),
    '#size' => 16,
    '#maxlength' => 16,
    '#description' => t('Played date/time format, uses PHP date() formats'),
  );
  return system_settings_form($form);
}
