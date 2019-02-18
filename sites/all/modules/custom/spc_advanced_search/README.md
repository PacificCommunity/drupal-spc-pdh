## Usage:
1. You need to copy **config.sample.json** file and name it **config.json**. In **config.json** define portal\portals where you want to search
2. For displaying search, you need just place ```<div id="advanced-search-application"></div>``` where you want or add block 'SPC Advanced search' to the page structure

3. For adding predefined filters, you need to add to **config.json** next options:

```
"predefined_facets": {
    "tags": ["test"],
    "res_format": ["PDF", "HTML"]
}
```

If you don't want to add predefined filters you shouldn't declare **predefined_facets** in **config.json** at all.
