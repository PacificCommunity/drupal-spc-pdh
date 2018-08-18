<?php
/**
 * @file
 * Default theme implementation for beans.
 *
 * Available variables:
 * - $content: An array of comment items. Use render($content) to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $title: The (sanitized) entity label.
 * - $url: Direct url of the current entity if specified.
 * - $page: Flag for the full page state.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available, where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity-{ENTITY_TYPE}
 *   - {ENTITY_TYPE}-{BUNDLE}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 */

?>
<?php if($show) : ?>
<div class="container">
	<div class="row">
	<div class="col-md-5 col-sm-6 col-xs-12">
		<h2><?php print $title; ?></h2>
		<h3><?php print t('View data and knowledge by Pacific Island country'); ?></h3>
	</div>

	<div class="col-md-7 col-sm-6 col-xs-12">
		<div class="dropdown">
		<div class="btn btn-default dropdown-toggle" id="memberCountries">
			<?php print t('Member Countries'); ?>
		</div>
		<ul>
			<li><a href="/" target="_blank">American Samoa</a></li>
			<li><a href="/" target="_blank">Cook Islands</a></li>
			<li><a href="/" target="_blank">Fiji</a></li>
			<li><a href="/" target="_blank">French Polynesia</a></li>
			<li><a href="/" target="_blank">Guam</a></li>
			<li><a href="/" target="_blank">Kiribati</a></li>
			<li><a href="/" target="_blank">Marshall Islands</a></li>
			<li><a href="/" target="_blank">Federated States of Micronesia</a></li>
			<li><a href="/" target="_blank">Nauru</a></li>
			<li><a href="/" target="_blank">New Caledonia</a></li>
			<li><a href="/" target="_blank">Niue</a></li>
			<li><a href="/" target="_blank">Northern Mariana Islands</a></li>
			<li><a href="/" target="_blank">Palau</a></li>
			<li><a href="/" target="_blank">Papua New Guinea</a></li>
			<li><a href="/" target="_blank">Pitcairn Islands</a></li>
			<li><a href="https://samoa-demo.spc.links.com.au/" target="_blank">Samoa</a></li>
			<li><a href="/" target="_blank">Solomon Islands</a></li>
			<li><a href="/" target="_blank">Tokelau</a></li>
			<li><a href="/" target="_blank">Tonga</a></li>
			<li><a href="/" target="_blank">Tuvalu</a></li>
			<li><a href="/" target="_blank">Vanuatu</a></li>
			<li><a href="/" target="_blank">Wallis and Futuna</a></li>
		</ul>
		</div>
	</div>
	</div>
</div>
<?php endif; ?>
