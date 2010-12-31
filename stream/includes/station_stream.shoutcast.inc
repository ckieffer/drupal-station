<?php

// Get cache
$cache = cache_get('station_stream');

// Load the cached data first, we'll overwrite if it's expired
$data = simplexml_load_string($cache->data);

// If the cache has expired or it doesn't exist, get stats from the server
if ($cache->expire < time() || !$cache) {
  $url = variable_get('station_stream_url', 'http://127.0.0.1');
  $port = variable_get('station_stream_port', '8000');
  $username = variable_get('station_stream_username', 'admin');
  $password = variable_get('station_stream_password', 'password');
  $useragent = 'Mozilla/5.001 (Drupal Station Stream module)';
  $headers = array('User-Agent' => $useragent, 'Authorization' => 'Basic ' .
      base64_encode($username . ':' . $password));

  $response = drupal_http_request("$url:$port/admin.cgi?mode=viewxml", $headers, 'GET');

  // The SHOUTcast server returned data, cache it
  if ($response->code == 200) {
    // Convert response string to object so that the request response code may be appended to it
    $data = simplexml_load_string($response->data);

    // Get the caching interval (in minutes) from the module's settings
    $interval = variable_get('station_stream_cachetime', 1);

    // Update the cache
    cache_set('station_stream', $response->data, 'cache', time() + ($interval * 60));

  // Throw an error is server didn't respond 200 OK
  } else {
    station_stream_error($response->code);
  }
}
