{
  "id" : 1617617242750,
  "name" : "Master",
  "comment" : "",
  "relativeDirectory" : "",
  "variables" : [ ],
  "masterPlan" : true,
  "utilityThreshold" : 0.0,
  "preCondition" : null,
  "runtimeCondition" : null,
  "entryPoints" : [ {
    "id" : 1617618015424,
    "name" : "1617618015424",
    "comment" : "",
    "successRequired" : false,
    "minCardinality" : 0,
    "maxCardinality" : 2147483647,
    "task" : "Taskrepository.tsk#1617616289767",
    "state" : 1617617300343,
    "plan" : 1617617242750
  } ],
  "states" : [ {
    "type" : "State",
    "id" : 1617617300343,
    "name" : "Init",
    "comment" : "",
    "entryPoint" : 1617618015424,
    "parentPlan" : 1617617242750,
    "confAbstractPlanWrappers" : [ {
      "id" : 1617618099598,
      "name" : "1617618099598",
      "comment" : "",
      "abstractPlan" : "Go2RandomPosition.beh#1617618064309",
      "configuration" : null
    } ],
    "variableBindings" : [ ],
    "outTransitions" : [ 1617617417528 ],
    "inTransitions" : [ 1617617440412 ]
  }, {
    "type" : "State",
    "id" : 1617617304997,
    "name" : "Move",
    "comment" : "",
    "entryPoint" : null,
    "parentPlan" : 1617617242750,
    "confAbstractPlanWrappers" : [ {
      "id" : 1617618136630,
      "name" : "1617618136630",
      "comment" : "",
      "abstractPlan" : "Move.pml#1617618120113",
      "configuration" : null
    } ],
    "variableBindings" : [ ],
    "outTransitions" : [ 1617617440412 ],
    "inTransitions" : [ 1617617417528 ]
  } ],
  "transitions" : [ {
    "id" : 1617617417528,
    "name" : "FromInitTo Move",
    "comment" : "MISSING_COMMENT",
    "inState" : 1617617300343,
    "outState" : 1617617304997,
    "preCondition" : {
      "id" : 1617617417531,
      "name" : "1617617417531",
      "comment" : "",
      "enabled" : true,
      "conditionString" : null,
      "pluginName" : "DefaultPlugin",
      "variables" : [ ],
      "quantifiers" : [ ]
    },
    "synchronisation" : null
  }, {
    "id" : 1617617440412,
    "name" : "FromMoveTo Init",
    "comment" : "MISSING_COMMENT",
    "inState" : 1617617304997,
    "outState" : 1617617300343,
    "preCondition" : {
      "id" : 1617617440413,
      "name" : "1617617440413",
      "comment" : "",
      "enabled" : true,
      "conditionString" : null,
      "pluginName" : "DefaultPlugin",
      "variables" : [ ],
      "quantifiers" : [ ]
    },
    "synchronisation" : null
  } ],
  "synchronisations" : [ ]
}