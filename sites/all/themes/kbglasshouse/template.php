<?php

/**
 * Preprocessor for node.tpl.php template file.
 */
function kbglasshouse_preprocess_node(&$vars) {
  tpl_field_vars_preprocess($vars, $vars['node'], array(
    'cleanup' => TRUE,
    'debug' => FALSE,
  ));
}

function kbglasshouse_handyblock() {
    return array(
        'recent_kbglasshouse_entries' => array(
            'block_info' => t('Recent Knowledge Base entries'),
            'theme_variables' => array( 'nodes' )
        ),
    );
}

/**
 * Handy Block alter callback for block 'recent_kbglasshouse_entries'.
 */
function kbglasshouse_handyblock_recent_kbglasshouse_entries_alter(&$block, $context) {
  $nodes = _kbglasshouse_node_get_recent();
  if (!empty($nodes) && is_array($nodes)) {
      foreach ($nodes as $node) {
          //$vars = tpl_field_vars($node);
          $block['content']['#nodes'][] = array('title' => $node->title, 'url' => 'node/' . $node->nid);
      }
  }
  
//  $block['content']['#theme'] = 'kbglasshouse_recent_kbglasshouse_entries';
}

//function kbglasshouse_block_view($delta = '') {
//  $block = array();
//
//  switch ($delta) {
//
//    case 'recent_kbglasshouse_entries':
//      if (user_access('access content')) {
//        $block['subject'] = t('Recent KB entries');
//        if ($nodes = _kbglasshouse_node_get_recent(variable_get('node_recent_block_count', 10))) {
//          $block['content'] = theme('node_recent_block', array(
//            'nodes' => $nodes,
//          ));
//        } else {
//          $block['content'] = t('No content available.');
//        }
//      }
//      break;
//  }
//  return $block;
//}
//
//function kbglasshouse_node_recent_content($variables) {
//    $node = $variables['node'];
//
//    $output = '<div class="node-title">';
//    $output .= l($node->title, 'node/' . $node->nid);
//    $output .= theme('mark', array('type' => node_mark($node->nid, $node->changed)));
//    $output .= '</div>';
//
//    return $output;
//}
//
//function kbglasshouse_node_recent_block($variables) {
//  $rows = array();
//  $output = '';
//
//  $l_options = array('query' => drupal_get_destination());
//  foreach ($variables['nodes'] as $node) {
//    $row = array();
//    $row[] = array(
//      'data' => theme('node_recent_content', array('node' => $node)),
//      'class' => 'title-author',
//    );
//    $row[] = array(
//      'data' => node_access('update', $node) ? l(t('edit'), 'node/' . $node->nid . '/edit', $l_options) : '',
//      'class' => node_access('update', $node) ? 'edit' : 'empty',
//    );
//    $row[] = array(
//      'data' => node_access('delete', $node) ? l(t('delete'), 'node/' . $node->nid . '/delete', $l_options) : '',
//      'class' => node_access('delete', $node) ? 'delete' : 'empty',
//    );
//    $rows[] = $row;
//  }
//
//  if ($rows) {
//    $output = theme('table', array('rows' => $rows));
//    if (user_access('access content overview')) {
//      $output .= theme('more_link', array('url' => 'admin/content', 'title' => t('Show more content')));
//    }
//  }
//
//  return $output;
//}

function _kbglasshouse_node_get_recent($number = 10) {
  $query = db_select('node', 'n');

  if (!user_access('bypass node access')) {
    // If the user is able to view their own unpublished nodes, allow them
    // to see these in addition to published nodes. Check that they actually
    // have some unpublished nodes to view before adding the condition.
    if (user_access('view own unpublished content') && $own_unpublished = db_query('SELECT nid FROM {node} WHERE uid = :uid AND status = :status', array(':uid' => $GLOBALS['user']->uid, ':status' => NODE_NOT_PUBLISHED))->fetchCol()) {
      $query->condition(db_or()
        ->condition('n.status', NODE_PUBLISHED)
        ->condition('n.nid', $own_unpublished, 'IN')
        ->condition('n.type', array('article'), 'IN')
      );
    }
    else {
      // If not, restrict the query to published nodes.
      $query->condition('n.status', NODE_PUBLISHED)->condition('n.type', array('article'), 'IN');
    }
  }
  $nids = $query
    ->fields('n', array('nid'))
    ->condition('n.type', array('article'), 'IN')
    ->orderBy('n.changed', 'DESC')
    ->range(0, $number)
    ->addTag('node_access')
    ->execute()
    ->fetchCol();

  $nodes = node_load_multiple($nids);

  return $nodes ? $nodes : array();
}
?>