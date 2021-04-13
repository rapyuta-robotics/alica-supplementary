{
  "id" : 1617618120113,
  "name" : "Move",
  "comment" : "",
  "relativeDirectory" : "",
  "variables" : [ ],
  "masterPlan" : false,
  "utilityThreshold" : 0.0,
  "preCondition" : null,
  "runtimeCondition" : {
    "id" : 1617618409499,
    "name" : "1617618409499",
    "comment" : "",
    "enabled" : true,
    "conditionString" : null,
    "pluginName" : "DefaultPlugin",
    "variables" : [ ],
    "quantifiers" : [ {
      "id" : 1617618441346,
      "name" : "NEW_QUANTIFIER",
      "comment" : "",
      "quantifierType" : "all",
      "scope" : 1617618120113,
      "sorts" : [ "x", "y" ]
    } ]
  },
  "entryPoints" : [ {
    "id" : 1617618274891,
    "name" : "1617618274891",
    "comment" : "",
    "successRequired" : false,
    "minCardinality" : 0,
    "maxCardinality" : 2147483647,
    "task" : "Taskrepository.tsk#1617618271079",
    "state" : 1617618155308,
    "plan" : 1617618120113
  }, {
    "id" : 1617618291624,
    "name" : "1617618291624",
    "comment" : "",
    "successRequired" : false,
    "minCardinality" : 1,
    "maxCardinality" : 1,
    "task" : "Taskrepository.tsk#1617618287507",
    "state" : 1617618158275,
    "plan" : 1617618120113
  } ],
  "states" : [ {
    "type" : "State",
    "id" : 1617618155308,
    "name" : "AlignSquare",
    "comment" : "",
    "entryPoint" : 1617618274891,
    "parentPlan" : 1617618120113,
    "confAbstractPlanWrappers" : [ {
      "id" : 1617629438710,
      "name" : "1617629438710",
      "comment" : "",
      "abstractPlan" : "GoTo.beh#1617618375823",
      "configuration" : null
    } ],
    "variableBindings" : [ ],
    "outTransitions" : [ ],
    "inTransitions" : [ ]
  }, {
    "type" : "State",
    "id" : 1617618158275,
    "name" : "Move2Center",
    "comment" : "",
    "entryPoint" : 1617618291624,
    "parentPlan" : 1617618120113,
    "confAbstractPlanWrappers" : [ {
      "id" : 1617629434526,
      "name" : "1617629434526",
      "comment" : "",
      "abstractPlan" : "GoTo.beh#1617618375823",
      "configuration" : null
    } ],
    "variableBindings" : [ ],
    "outTransitions" : [ ],
    "inTransitions" : [ ]
  } ],
  "transitions" : [ ],
  "synchronisations" : [ ]
}