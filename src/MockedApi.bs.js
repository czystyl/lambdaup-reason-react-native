// Generated by BUCKLESCRIPT VERSION 4.0.5, PLEASE EDIT WITH CARE
'use strict';

var Block = require("bs-platform/lib/js/block.js");
var Random = require("bs-platform/lib/js/random.js");

var data = /* :: */[
  /* record */[
    /* firstName */"Jakub",
    /* lastName */"Klobus",
    /* id */0
  ],
  /* :: */[
    /* record */[
      /* firstName */"Matt",
      /* lastName */"Zatorski",
      /* id */1
    ],
    /* :: */[
      /* record */[
        /* firstName */"Luke",
        /* lastName */"Czyszczonik",
        /* id */2
      ],
      /* :: */[
        /* record */[
          /* firstName */"Adam",
          /* lastName */"Malysz",
          /* id */3
        ],
        /* :: */[
          /* record */[
            /* firstName */"Lambd",
            /* lastName */"Up",
            /* id */4
          ],
          /* :: */[
            /* record */[
              /* firstName */"Mike",
              /* lastName */"Grabowski",
              /* id */5
            ],
            /* [] */0
          ]
        ]
      ]
    ]
  ]
];

function getData() {
  Random.self_init(/* () */0);
  var randomValue = Random.$$int(4);
  if (randomValue !== 0) {
    if (randomValue !== 1) {
      return /* Response */Block.__(0, [
                200,
                data
              ]);
    } else {
      return /* Response */Block.__(0, [
                200,
                /* [] */0
              ]);
    }
  } else {
    return /* Error */Block.__(1, [
              404,
              "Cannot find data"
            ]);
  }
}

exports.data = data;
exports.getData = getData;
/* No side effect */
