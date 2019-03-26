## Usage:
1. You need to copy **config.sample.json** file and name it **config.json**. In **config.json** define portal\portals where you want to search
2. For displaying search, you need just place the block 'SPC Advanced search' on the page you would like to enable the advanced search. Alternatively, the module provides the following token to embed the search: [advanced_search:pdh_advanced_search]

3. For adding predefined filters, you need to add to **config.json** next options:

```
"predefined_facets": {
    "tags": ["test"],
    "res_format": ["PDF", "HTML"]
}
```

IMPORTANT: If you don't want to add predefined filters you shouldn't declare **predefined_facets** in **config.json** at all.

NOTE: default config settings are pointing to Pacific Data Hub
