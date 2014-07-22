<?php

/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */
?>
<?php 
$height1 = $fields['field_height_1']->content * 2;
$margin1 = 200 - $height1;
$height2 = $fields['field_height_2']->content * 2;
$margin2 = 200 - $height2;
?>
<div class="slideshow-bar" style="height: <?php print $height1; ?>px; margin-top: <?php print $margin1; ?>px; background-color: <?php print $fields['field_bar_1']->content; ?>;"></div>
<?php print $fields['field_arrow_1']->content; ?>
<div class="slideshow-text slideshow-text-1"><?php print $fields['field_text_1']->content; ?></div>
<div class="slideshow-bar" style="height: <?php print $height2; ?>px; margin-top: <?php print $margin2; ?>px; background-color: <?php print $fields['field_bar_2']->content; ?>;"></div>
<?php print $fields['field_arrow_2']->content; ?>
<div class="slideshow-text slideshow-text-2"><?php print $fields['field_text_2']->content; ?></div>

