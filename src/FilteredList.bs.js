// Generated by BUCKLESCRIPT VERSION 4.0.5, PLEASE EDIT WITH CARE
'use strict';

var List = require("bs-platform/lib/js/list.js");
var $$Array = require("bs-platform/lib/js/array.js");
var Block = require("bs-platform/lib/js/block.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var Js_primitive = require("bs-platform/lib/js/js_primitive.js");
var Text$BsReactNative = require("bs-react-native/src/components/text.js");
var View$BsReactNative = require("bs-react-native/src/components/view.js");
var Style$BsReactNative = require("bs-react-native/src/style.js");
var FlatList$BsReactNative = require("bs-react-native/src/components/flatList.js");
var TextInput$BsReactNative = require("bs-react-native/src/components/textInput.js");
var Colors$LambdaReasonReactNative = require("./Colors.bs.js");

var itemContainer = Style$BsReactNative.style(/* :: */[
      Style$BsReactNative.padding(/* Pt */Block.__(0, [15])),
      /* :: */[
        Style$BsReactNative.borderBottomWidth(1),
        /* :: */[
          Style$BsReactNative.borderBottomColor(Colors$LambdaReasonReactNative.light),
          /* [] */0
        ]
      ]
    ]);

var input = Style$BsReactNative.style(/* :: */[
      Style$BsReactNative.padding(/* Pt */Block.__(0, [10])),
      /* :: */[
        Style$BsReactNative.margin(/* Pt */Block.__(0, [10])),
        /* :: */[
          Style$BsReactNative.borderRadius(5),
          /* :: */[
            Style$BsReactNative.borderWidth(1),
            /* :: */[
              Style$BsReactNative.borderColor(Colors$LambdaReasonReactNative.gray),
              /* [] */0
            ]
          ]
        ]
      ]
    ]);

var Styles = /* module */[
  /* itemContainer */itemContainer,
  /* input */input
];

function renderItem(param) {
  return FlatList$BsReactNative.renderItem((function ($$event) {
                return ReasonReact.element(undefined, undefined, View$BsReactNative.make(undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, Js_primitive.some(itemContainer), undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined)(/* array */[ReasonReact.element(undefined, undefined, Text$BsReactNative.make(undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, /* array */[$$event[/* item */0][/* firstName */0] + (" " + $$event[/* item */0][/* lastName */1])]))]));
              }), param);
}

var component = ReasonReact.statelessComponent("FilteredList");

function make(data, onRefresh, onChangeQuery, searchQuery, _) {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */component[/* didMount */4],
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function () {
              var filteredData = List.filter((function (item) {
                        return (item[/* firstName */0] + item[/* lastName */1]).includes(searchQuery);
                      }))(data);
              return ReasonReact.element(undefined, undefined, View$BsReactNative.make(undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined)(/* array */[
                              ReasonReact.element(undefined, undefined, TextInput$BsReactNative.make(undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, Js_primitive.some(input), undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, onChangeQuery, undefined, undefined, undefined, undefined, undefined, undefined, "search", undefined, undefined, undefined, undefined, undefined, undefined, searchQuery, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined)(/* array */[])),
                              ReasonReact.element(undefined, undefined, FlatList$BsReactNative.make($$Array.of_list(filteredData), renderItem, (function ($$event, _) {
                                            return String($$event[/* id */2]);
                                          }), undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, onRefresh, undefined, undefined, undefined, false, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined)(/* array */[]))
                            ]));
            }),
          /* initialState */component[/* initialState */10],
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */component[/* reducer */12],
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

exports.Styles = Styles;
exports.renderItem = renderItem;
exports.component = component;
exports.make = make;
/* itemContainer Not a pure module */
