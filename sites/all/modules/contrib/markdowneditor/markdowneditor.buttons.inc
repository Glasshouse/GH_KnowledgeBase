<?php
/**
 * @file
 * Buttons for the markdowneditor module.
 *
 */

/*
 * Markdown Editor
 * by Jakob Persson of NodeOne <jakob@nodeone.se>
 *
 * Provides a toolbar for writing Markdown syntax with BUEditor.
 *
 * Sponsored by
 *   NodeOne - www.nodeone.se
 */

$ajax_markup_exist = module_exists('ajax_markup') ? 'ajax_markup_exist' : NULL;
$imce_url = module_exists('imce') ? url('imce/browse') : NULL;
$js_imceURL = $imce_url ? "markdownEditor.settings.IMCEPath = '$imce_url';" : '';

// Define buttons
//
// 0: eid
// 1: title
// 2: code/content
// 3: image
// 4: shortcut key
// 5: weight

$mde_buttons = array();

// Increment counter for array keys
$i = 0;

$mde_buttons[$i++] = array(
  $eid,
  t("Make selected text into a header"),
  "js: $js_imceURL markdownEditor.header();",
  "md-make-header.gif",
  "H",
  -10,
);

$mde_buttons[$i++] = array(
  $eid,
  t("Italics: Make selected text emphasized"),
  "js: markdownEditor.emphasis();",
  "md-make-em.gif",
  "I",
  -9,
);

$mde_buttons[$i++] = array(
  $eid,
  t("Make selected text strong"),
  "js: markdownEditor.strongEmphasis();",
  "md-make-strong.gif",
  "B",
  -8,
);

$mde_buttons[$i++] = array(
  $eid,
  t("Format selected text as code"),
  "js: markdownEditor.codeInline();",
  "md-make-code.gif",
  "",
  -7,
);

$mde_buttons[$i++] = array(
  $eid,
  t("Format selected text as a code block"),
  "js: markdownEditor.codeBlock();",
  "md-make-code-block.gif",
  "",
  -6,
);

$mde_buttons[$i++] = array(
  $eid,
  t("Make selected text into a block quote"),
  "js: markdownEditor.blockQuote();",
  "md-make-quote.gif",
  "Q",
  -5,
);

$mde_buttons[$i++] = array(
  $eid,
  t("Make selected text into an ordered list (numbered)"),
  "js: markdownEditor.orderedList();",
  "md-make-ol.gif",
  "O",
  -4,
);

$mde_buttons[$i++] = array(
  $eid,
  t("Make selected text into an unordered list (bullets)"),
  "js: markdownEditor.unorderedList();",
  "md-make-ul.gif",
  "N",
  -3,
);

$mde_buttons[$i++] = array(
  $eid,
  t("Insert a definition list"),
  "js: $js_imceURL new markdownEditor.DefinitionList();",
  "md-add-dl.gif",
  "",
  -2,
);

$mde_buttons[$i++] = array(
  $eid,
  t("Insert a table"),
  "js: $js_imceURL new markdownEditor.Table();",
  "md-add-table.gif",
  "T",
  -1,
);

$mde_buttons[$i++] = array(
  $eid,
  ("Insert an abbreviation (word or acronym with definition)"),
  "js: $js_imceURL markdownEditor.abbreviation();",
  "md-add-abbreviation.gif",
  "",
  0,
);

$mde_buttons[$i++] = array(
  $eid,
  t("Insert a footnote"),
  "js: $js_imceURL markdownEditor.footnote();",
  "md-add-footnote.gif",
  "F",
  1,
);

$mde_buttons[$i++] = array(
  $eid,
  t("Make text into an autolink (turns URLs in links, turns words into section identifiers for navigating the document)"),
  "js: $js_imceURL markdownEditor.autoLink();",
  "md-add-autolink.gif",
  "A",
  2,
);

$mde_buttons[$i++] = array(
  $eid,
  t("Make text into a link (turns text into a link with more options)"),
  "js: $js_imceURL markdownEditor.link();",
  "md-make-link.gif",
  "L",
  3,
);

$mde_buttons[$i++] = array(
  $eid,
  t("Insert an image"),
  "js: $js_imceURL markdownEditor.image();",
  "md-add-picture.gif",
  "M",
  4,
);

$mde_buttons[$i++] = array(
  $eid,
  t("Insert a line break"),
  "js: markdownEditor.lineBreak();",
  "md-add-line.gif",
  "R",
  5,
);

$mde_buttons[$i++] = array(
  $eid,
  t("Insert a horizontal ruler (horizontal line)"),
  "js: markdownEditor.horizontalRuler();",
  "md-add-hr.gif",
  "",
  6,
);

$mde_buttons[$i++] = array(
  $eid,
  t("Teaser break"),
  "<!--break-->",
  "teaserbr.png",
  "T",
  7,
);

if (module_exists('ajax_markup')) {
  $mde_buttons[$i++] = array(
    $eid,
    t("Preview"),
    "js: E.prvAjax();",
    "preview.png",
    "P",
    8,
  );
}

$mde_buttons[$i++] = array(
  $eid,
  t("Help"),
  "js: E.help('fadeIn');",
  "md-help.gif",
  "",
  9,
);

// EoF
