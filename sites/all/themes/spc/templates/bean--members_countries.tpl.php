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

<?php if ($show) : ?>
	<div id="member-countries-block">
		<div class="block-content">
			<div class="left-column column">
				<div class="column-inner">
					<div class="column-header">
						<h2><?php print $title; ?></h2>
						<p><?php print t('View data and knowledge by Pacific Island country'); ?></p>					
						<div class="dropdown">
							<div 
								class="btn btn-default dropdown-toggle" 
								id="memberCountries" 
								data-toggle="dropdown" 
								aria-haspopup="true" 
								aria-expanded="true"
							>
								<?php print t('Member Countries'); ?>
							</div>
							<?php if (!empty($variables['field_members_countries'])) : ?>
								<ul class="dropdown-menu">
									<?php foreach (element_children($variables['field_members_countries']) as $children_key) : ?>
										<li><?php print drupal_render($content['field_members_countries'][$children_key]); ?></li>
									<?php endforeach; ?>
								</ul>
							<?php endif; ?>
						</div>
					</div>
					<div class="column-footer">
						<div class="datasets-count">
							<span class="datasets-icon"></span>
							<div class="count">
								<div class="amount">0</div>
								<div class="description"><?php print t('Datasets'); ?></div>
							</div>
						</div>
						<div class="datasets-link">
							<a href="" target="_blank"><span class="arrow-right-icon"></span></a>
						</div>
					</div>
				</div>
			</div>
			<div class="right-column column">
					<div class="column-inner">
						<div class="map-container"></div>
					</div>
			</div>
		</div>
	</div>
<?php endif; ?>