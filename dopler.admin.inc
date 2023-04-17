<?php

function dopler_admin_form($form, $form_state): array {
  $form['dopler_d7_status'] = [
    '#type'          => 'checkbox',
    '#title'         => t('Enable Service'),
    '#default_value' => variable_get('dopler_d7_status', TRUE),
    '#description'   => t('Enable / Disable the Dopler Service'),
  ];

  $form['dopler_d7_api'] = [
    '#type'        => 'fieldset',
    '#title'       => t('Dopler Server Settings'),
    '#collapsible' => TRUE,
    '#collapsed'   => TRUE,
  ];

  $form['dopler_d7_api']['dopler_d7_server'] = [
    '#title'         => t('Server URL'),
    '#description'   => t('Fully qualified name of the Dopler Server'),
    '#type'          => 'textfield',
    '#default_value' => variable_get('dopler_d7_server'),
    '#size'          => 60,
    '#maxlength'     => 255,
    '#required'      => TRUE,
  ];

  $form['dopler_d7_api']['dopler_d7_account_token'] = [
    '#title'         => t('Account Token'),
    '#description'   => t('The token for your account (organization) on Dopler'),
    '#type'          => 'textfield',
    '#default_value' => variable_get('dopler_d7_account_token'),
    '#size'          => 64,
    '#maxlength'     => 64,
    '#required'      => TRUE,
  ];

  $form['dopler_d7_api']['dopler_d7_user_token'] = [
    '#title'         => t('User Token'),
    '#description'   => t('The token for your user account on Dopler'),
    '#type'          => 'textfield',
    '#default_value' => variable_get('dopler_d7_user_token'),
    '#size'          => 64,
    '#maxlength'     => 128,
    '#required'      => TRUE,
  ];

  $form['dopler_d7_api']['dopler_d7_server_environment_var'] = [
    '#title'         => t('Server Environment Variable'),
    '#description'   => t('The $_SERVER environment variable that will give us the server environment'),
    '#type'          => 'textfield',
    '#default_value' => variable_get('dopler_d7_server_environment_var'),
    '#size'          => 64,
    '#maxlength'     => 128,
    '#required'      => FALSE,
  ];

  $form['dopler_d7_api']['dopler_d7_server_environment'] = [
    '#title'         => t('Server Environment'),
    '#description'   => t('If there is no $_SERVER variable, what is the name of this environment'),
    '#type'          => 'textfield',
    '#default_value' => variable_get('dopler_d7_server_environment'),
    '#size'          => 64,
    '#maxlength'     => 128,
    '#required'      => FALSE,
  ];

  $form['dopler_d7_entities'] = [
    '#type'        => 'fieldset',
    '#title'       => t('Dopler Entity Settings'),
    '#collapsible' => TRUE,
    '#collapsed'   => FALSE,
  ];
  $form['dopler_d7_entities']['dopler_d7_node'] = [
    '#title'         => t('Enable Nodes'),
    '#description'   => t('Enable the service for node events'),
    '#type'          => 'checkbox',
    '#default_value' => variable_get('dopler_d7_node', TRUE),
  ];
  $form['dopler_d7_entities']['dopler_d7_taxonomy_term'] = [
    '#title'         => t('Enable Terms'),
    '#description'   => t('Enable the service for taxonomy term events'),
    '#type'          => 'checkbox',
    '#default_value' => variable_get('dopler_d7_taxonomy_term', TRUE),
  ];
  $form['dopler_d7_entities']['dopler_d7_user'] = [
    '#title'         => t('Enable Users'),
    '#description'   => t('Enable the service for user events'),
    '#type'          => 'checkbox',
    '#default_value' => variable_get('dopler_d7_user', TRUE),
  ];
  $form['dopler_d7_entities']['dopler_d7_custom'] = [
    '#title'         => t('Enable Custom'),
    '#description'   => t('Enable the service for custom events'),
    '#type'          => 'checkbox',
    '#default_value' => variable_get('dopler_d7_custom', TRUE),
  ];
  $form['dopler_d7_entities']['dopler_viewed_paths'] = [
    '#title'         => t('Viewed Paths'),
    '#description'   => t('Any paths listed here will trigger a <strong>viewed</strong> event<br/>
      Please use sparingly - this will add overhead to your system.<br/>
      You should add one path per line, and probably the ones that will be viewed most should be at the top.'),
    '#type'          => 'textarea',
    '#default_value' => variable_get('dopler_viewed_paths'),
    '#rows'          => 10,
  ];

  return system_settings_form($form);
}