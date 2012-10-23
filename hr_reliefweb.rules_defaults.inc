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
      "TAGS" : [ "reliefweb" ],
      "REQUIRES" : [ "rules", "custom_pub" ],
      "ON" : [ "node_insert" ],
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
            "message" : "A new document was submitted on [site:url].\\u000D\\u000A\\u000D\\u000AThe document can be seen here: \\u000D\\u000A[node:url]\\u000D\\u000A\\u000D\\u000AThe document metadata are the following:\\u000D\\u000ATitle: [node:title]\\u000D\\u000AType: [node:field-document-type]\\u000D\\u000ACluster(s): [node:field-clusters]\\u000D\\u000ATheme(s): [node:field-themes]",
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
      "TAGS" : [ "reliefweb" ],
      "REQUIRES" : [ "rules", "custom_pub" ],
      "ON" : [ "node_insert" ],
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "map" : "map" } } } },
        { "custom_pub_node_has_option" : { "node" : [ "node" ], "option" : "reliefweb" } }
      ],
      "DO" : [
        { "mail" : {
            "to" : "maps@reliefweb.int",
            "subject" : "[HumanitarianResponse] New visual submitted on [site:url]",
            "message" : "A new visual was submitted on [site:url].\\u000D\\u000A\\u000D\\u000AYou can see it here:\\u000D\\u000A[node:url]\\u000D\\u000A\\u000D\\u000AThe visual metadata are the following:\\u000D\\u000ATitle: [node:title]\\u000D\\u000AType: [node:field-map-type]\\u000D\\u000ACluster(s): [node:field-clusters]\\u000D\\u000ATheme(s): [node:field-themes]",
            "from" : "info@humanitarianresponse.info",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  return $items;
}
