<?php
/**
 * @file
 * hr_reliefweb.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function hr_reliefweb_default_rules_configuration() {
  $items = array();
  $items['rules_submit_documents_to_reliefweb'] = entity_import('rules_config', '{ "rules_submit_documents_to_reliefweb" : {
      "LABEL" : "Submit Documents to Reliefweb",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "reliefweb" ],
      "REQUIRES" : [ "rules", "custom_pub" ],
      "ON" : { "node_insert" : [] },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "document" : "document" } }
          }
        },
        { "custom_pub_node_has_option" : { "node" : [ "node" ], "option" : "reliefweb" } }
      ],
      "DO" : [
        { "mail" : {
            "to" : "submit@reliefweb.int",
            "subject" : "[HumanitarianResponse] New document submitted on [site:url]",
            "message" : "A new document was submitted on [site:url].\\r\\n\\r\\nThe document can be seen here: \\r\\n[node:url]\\r\\n\\r\\nThe document metadata are the following:\\r\\nTitle: [node:title]\\r\\nType: [node:field-document-type]\\r\\nCluster(s): [node:field-clusters]\\r\\nTheme(s): [node:field-themes]",
            "from" : "info@humanitarianresponse.info",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_submit_visuals_to_reliefweb'] = entity_import('rules_config', '{ "rules_submit_visuals_to_reliefweb" : {
      "LABEL" : "Submit Visuals to Reliefweb",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "reliefweb" ],
      "REQUIRES" : [ "rules", "custom_pub" ],
      "ON" : { "node_insert" : [] },
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "map" : "map" } } } },
        { "custom_pub_node_has_option" : { "node" : [ "node" ], "option" : "reliefweb" } }
      ],
      "DO" : [
        { "mail" : {
            "to" : "maps@reliefweb.int",
            "subject" : "[HumanitarianResponse] New visual submitted on [site:url]",
            "message" : "A new visual was submitted on [site:url].\\r\\n\\r\\nYou can see it here:\\r\\n[node:url]\\r\\n\\r\\nThe visual metadata are the following:\\r\\nTitle: [node:title]\\r\\nType: [node:field-map-type]\\r\\nCluster(s): [node:field-clusters]\\r\\nTheme(s): [node:field-themes]",
            "from" : "info@humanitarianresponse.info",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  return $items;
}
