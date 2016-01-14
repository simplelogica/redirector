<?php

function redirector_list() {
  $header = [t('Pattern'), t('Target'), t('Code'), t('Edit'), t('Delete')];
  $destination = drupal_get_destination();
  $rows = array_map(function ($redirection) use ($destination) {
    return [
      nl2br($redirection->patterns),
      htmlentities($redirection->target),
      htmlentities($redirection->code),
      l('edit', "admin/config/search/redirector/{$redirection->rid}/edit"),
      l('delete', "admin/config/search/redirector/{$redirection->rid}/delete"),
    ];
  }, _get_redirections());
  return theme('table', ['header' => $header, 'rows' => $rows]);
}


// DELETE FORM

function redirection_delete_form($form, &$form_state, $redirection_id) {
  $form['rid'] = [
    '#type' => 'value',
    '#value' => $redirection_id,
  ];
  return confirm_form($form,
    t('Are you sure you want to delete this redirection?'),
    'admin/config/search/redirector');
}

function redirection_delete_form_submit($form, &$form_state) {
  _delete_redirection($form_state['values']['rid']);
  drupal_set_message(t('The redirection has been successfully deleted'));
  $form_state['redirect'] = 'admin/config/search/redirector';
}

// EDIT FORM

function redirection_edit_form($form, &$form_state, $redirection_id) {
  $redirection = $redirection_id ? _get_redirection($redirection_id) : new stdClass();
  $form['rid'] = [
    '#type' => 'value',
    '#value' => isset($redirection->rid) ? $redirection->rid : null,
  ];
  $form['patterns'] = [
    '#type' => 'textarea',
    '#title' => t('Patterns'),
    '#description' => t('Use asterisks (*) for wildcards'),
    '#default_value' => isset($redirection->patterns) ? $redirection->patterns : null,
    '#required' => true,
  ];
  $form['target'] = [
    '#type' => 'textfield',
    '#title' => t('Target'),
    '#description' => t('Use &lt;front&gt; for the front page'),
    '#default_value' => isset($redirection->target) ? $redirection->target : null,
    '#required' => true,
  ];
  $form['code'] = [
    '#type' => 'select',
    '#title' => t('Status code'),
    '#options' => [
      300 => t('300 (Multiple Choices)'),
      301 => t('301 (Moved Permanently)'),
      302 => t('302 (Found)'),
      303 => t('303 (See Other)'),
      304 => t('304 (Not Modified)'),
      305 => t('305 (Use Proxy)'),
      307 => t('307 (Temporary Redirect)'),
    ],
    '#default_value' => isset($redirection->code) ? $redirection->code : null,
    '#require' => true,
  ];
  $form['actions'] = [
    '#type' => 'actions',
    'submit' => [
      '#type' => 'submit',
      '#value' => t('Save'),
    ],
  ];
  return $form;
}

function redirection_edit_form_submit($form, &$form_state) {
  $values = [
    'patterns' => $form_state['values']['patterns'],
    'target' => $form_state['values']['target'],
    'code' => $form_state['values']['code'],
  ];
  if (isset($form_state['values']['rid'])) {
    _edit_redirection($form_state['values']['rid'], $values);
    drupal_set_message(t('The redirection has been successfully updated'));
  } else {
    _add_redirection($values);
    drupal_set_message(t('The redirection has been successfully created'));
  }
  $form_state['redirect'] = 'admin/config/search/redirector';
}