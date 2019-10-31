<?php

/**
 * @file
 * spc_menus.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function spc_menus_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_climate-change:node/9.
  $menu_links['main-menu_climate-change:node/9'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/9',
    'router_path' => 'node/%',
    'link_title' => 'Climate Change',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_climate-change:node/9',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'main-menu_topics:<front>',
  );
  // Exported menu link: main-menu_data-insights:data-insights.
  $menu_links['main-menu_data-insights:data-insights'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'data-insights',
    'router_path' => 'data-insights',
    'link_title' => 'Data Insights',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_data-insights:data-insights',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: main-menu_datasets:https://dev.spc.links.com.au/data/.
  $menu_links['main-menu_datasets:https://dev.spc.links.com.au/data/'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'https://dev.spc.links.com.au/data/',
    'router_path' => '',
    'link_title' => 'Datasets',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_datasets:https://dev.spc.links.com.au/data/',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: main-menu_economic-development:node/11.
  $menu_links['main-menu_economic-development:node/11'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/11',
    'router_path' => 'node/%',
    'link_title' => 'Economic Development',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_economic-development:node/11',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 1,
    'customized' => 1,
    'parent_identifier' => 'main-menu_topics:<front>',
  );
  // Exported menu link: main-menu_education:node/12.
  $menu_links['main-menu_education:node/12'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/12',
    'router_path' => 'node/%',
    'link_title' => 'Education',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_education:node/12',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 2,
    'customized' => 1,
    'parent_identifier' => 'main-menu_topics:<front>',
  );
  // Exported menu link: main-menu_energy:node/13.
  $menu_links['main-menu_energy:node/13'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/13',
    'router_path' => 'node/%',
    'link_title' => 'Energy',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_energy:node/13',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 3,
    'customized' => 1,
    'parent_identifier' => 'main-menu_topics:<front>',
  );
  // Exported menu link: main-menu_fisheries:node/14.
  $menu_links['main-menu_fisheries:node/14'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/14',
    'router_path' => 'node/%',
    'link_title' => 'Fisheries',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_fisheries:node/14',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 4,
    'customized' => 1,
    'parent_identifier' => 'main-menu_topics:<front>',
  );
  // Exported menu link: main-menu_geoscience:node/8.
  $menu_links['main-menu_geoscience:node/8'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/8',
    'router_path' => 'node/%',
    'link_title' => 'Geoscience',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_geoscience:node/8',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 5,
    'customized' => 1,
    'parent_identifier' => 'main-menu_topics:<front>',
  );
  // Exported menu link: main-menu_health:node/15.
  $menu_links['main-menu_health:node/15'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/15',
    'router_path' => 'node/%',
    'link_title' => 'Health',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_health:node/15',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 6,
    'customized' => 1,
    'parent_identifier' => 'main-menu_topics:<front>',
  );
  // Exported menu link: main-menu_home:<front>.
  $menu_links['main-menu_home:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Home',
    'options' => array(
      'attributes' => array(
        'id' => 'home-id',
        'name' => 'home-name',
        'rel' => 'home-Relationship',
        'class' => array(
          0 => 'home-class',
        ),
      ),
      'item_attributes' => array(
        'id' => 'home-item-id',
        'class' => 'home-item-class',
        'style' => '',
      ),
      'identifier' => 'main-menu_home:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: main-menu_human-rights:node/16.
  $menu_links['main-menu_human-rights:node/16'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/16',
    'router_path' => 'node/%',
    'link_title' => 'Human Rights',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_human-rights:node/16',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 7,
    'customized' => 1,
    'parent_identifier' => 'main-menu_topics:<front>',
  );
  // Exported menu link: main-menu_land-resources:node/17.
  $menu_links['main-menu_land-resources:node/17'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/17',
    'router_path' => 'node/%',
    'link_title' => 'Land Resources',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_land-resources:node/17',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 8,
    'customized' => 1,
    'parent_identifier' => 'main-menu_topics:<front>',
  );
  // Exported menu link: main-menu_organizations:https://dev.spc.links.com.au/data/organization.
  $menu_links['main-menu_organizations:https://dev.spc.links.com.au/data/organization'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'https://dev.spc.links.com.au/data/organization',
    'router_path' => '',
    'link_title' => 'Organizations',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_organizations:https://dev.spc.links.com.au/data/organization',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: main-menu_social:node/18.
  $menu_links['main-menu_social:node/18'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/18',
    'router_path' => 'node/%',
    'link_title' => 'Social',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_social:node/18',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 9,
    'customized' => 1,
    'parent_identifier' => 'main-menu_topics:<front>',
  );
  // Exported menu link: main-menu_statistics:node/19.
  $menu_links['main-menu_statistics:node/19'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/19',
    'router_path' => 'node/%',
    'link_title' => 'Statistics',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_statistics:node/19',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 10,
    'customized' => 1,
    'parent_identifier' => 'main-menu_topics:<front>',
  );
  // Exported menu link: main-menu_topics:<front>.
  $menu_links['main-menu_topics:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Topics',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_topics:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: management_administration-menu:admin/config/administration/admin-menu.
  $menu_links['management_administration-menu:admin/config/administration/admin-menu'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/administration/admin-menu',
    'router_path' => 'admin/config/administration/admin-menu',
    'link_title' => 'Administration menu',
    'options' => array(
      'attributes' => array(
        'title' => 'Adjust administration menu settings.',
      ),
      'identifier' => 'management_administration-menu:admin/config/administration/admin-menu',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_administration:admin/config/administration',
  );
  // Exported menu link: management_main-menu:admin/structure/menu/manage/main-menu.
  $menu_links['management_main-menu:admin/structure/menu/manage/main-menu'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/menu/manage/main-menu',
    'router_path' => 'admin/structure/menu/manage/%',
    'link_title' => 'Main menu',
    'options' => array(
      'identifier' => 'management_main-menu:admin/structure/menu/manage/main-menu',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_menus:admin/structure/menu',
  );
  // Exported menu link: management_menus:admin/structure/menu.
  $menu_links['management_menus:admin/structure/menu'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/menu',
    'router_path' => 'admin/structure/menu',
    'link_title' => 'Menus',
    'options' => array(
      'attributes' => array(
        'title' => 'Add new menus to your site, edit existing menus, and rename and reorganize menu links.',
      ),
      'identifier' => 'management_menus:admin/structure/menu',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_structure:admin/structure',
  );
  // Exported menu link: management_user-menu:admin/structure/menu/manage/user-menu.
  $menu_links['management_user-menu:admin/structure/menu/manage/user-menu'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/menu/manage/user-menu',
    'router_path' => 'admin/structure/menu/manage/%',
    'link_title' => 'User menu',
    'options' => array(
      'identifier' => 'management_user-menu:admin/structure/menu/manage/user-menu',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_menus:admin/structure/menu',
  );
  // Exported menu link: menu-resources-menu_faq:node/31.
  $menu_links['menu-resources-menu_faq:node/31'] = array(
    'menu_name' => 'menu-resources-menu',
    'link_path' => 'node/31',
    'router_path' => 'node/%',
    'link_title' => 'FAQ',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-resources-menu_faq:node/31',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-resources-menu_member-countries:node/31.
  $menu_links['menu-resources-menu_member-countries:node/31'] = array(
    'menu_name' => 'menu-resources-menu',
    'link_path' => 'node/31',
    'router_path' => 'node/%',
    'link_title' => 'Member Countries',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-resources-menu_member-countries:node/31',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-resources-menu_privacy-policy:node/31.
  $menu_links['menu-resources-menu_privacy-policy:node/31'] = array(
    'menu_name' => 'menu-resources-menu',
    'link_path' => 'node/31',
    'router_path' => 'node/%',
    'link_title' => 'Privacy Policy',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-resources-menu_privacy-policy:node/31',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-resources-menu_sitemap:node/31.
  $menu_links['menu-resources-menu_sitemap:node/31'] = array(
    'menu_name' => 'menu-resources-menu',
    'link_path' => 'node/31',
    'router_path' => 'node/%',
    'link_title' => 'Sitemap',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-resources-menu_sitemap:node/31',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-who-we-are-menu_about-us:node/77.
  $menu_links['menu-who-we-are-menu_about-us:node/77'] = array(
    'menu_name' => 'menu-who-we-are-menu',
    'link_path' => 'node/77',
    'router_path' => 'node/%',
    'link_title' => 'About Us',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-who-we-are-menu_about-us:node/77',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-who-we-are-menu_contact-us:node/78.
  $menu_links['menu-who-we-are-menu_contact-us:node/78'] = array(
    'menu_name' => 'menu-who-we-are-menu',
    'link_path' => 'node/78',
    'router_path' => 'node/%',
    'link_title' => 'Contact Us',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-who-we-are-menu_contact-us:node/78',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-who-we-are-menu_member:node/31.
  $menu_links['menu-who-we-are-menu_member:node/31'] = array(
    'menu_name' => 'menu-who-we-are-menu',
    'link_path' => 'node/31',
    'router_path' => 'node/%',
    'link_title' => 'Member',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-who-we-are-menu_member:node/31',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-who-we-are-menu_privacy-policy:node/79.
  $menu_links['menu-who-we-are-menu_privacy-policy:node/79'] = array(
    'menu_name' => 'menu-who-we-are-menu',
    'link_path' => 'node/79',
    'router_path' => 'node/%',
    'link_title' => 'Privacy Policy',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-who-we-are-menu_privacy-policy:node/79',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-who-we-are-menu_staff-email:node/31.
  $menu_links['menu-who-we-are-menu_staff-email:node/31'] = array(
    'menu_name' => 'menu-who-we-are-menu',
    'link_path' => 'node/31',
    'router_path' => 'node/%',
    'link_title' => 'Staff Email',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-who-we-are-menu_staff-email:node/31',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: user-menu_log-out:user/logout.
  $menu_links['user-menu_log-out:user/logout'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/logout',
    'router_path' => 'user/logout',
    'link_title' => 'Log out',
    'options' => array(
      'identifier' => 'user-menu_log-out:user/logout',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 10,
    'customized' => 0,
  );
  // Exported menu link: user-menu_user-account:user.
  $menu_links['user-menu_user-account:user'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'User account',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'user-menu_user-account:user',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -10,
    'customized' => 0,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('About Us');
  t('Administration menu');
  t('Climate Change');
  t('Contact Us');
  t('Data Insights');
  t('Datasets');
  t('Economic Development');
  t('Education');
  t('Energy');
  t('FAQ');
  t('Fisheries');
  t('Geoscience');
  t('Health');
  t('Home');
  t('Human Rights');
  t('Land Resources');
  t('Log out');
  t('Main menu');
  t('Member');
  t('Member Countries');
  t('Menus');
  t('Organizations');
  t('Privacy Policy');
  t('Sitemap');
  t('Social');
  t('Staff Email');
  t('Statistics');
  t('Topics');
  t('User account');
  t('User menu');

  return $menu_links;
}
