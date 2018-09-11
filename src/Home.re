open BsReactNative;

module Styles = {
  open Style;

  let container = style([paddingTop(Pt(30.))]);
};

let component = ReasonReact.statelessComponent("Home");

let make = _children => {
  ...component,
  render: _self => {
    let response = MockedApi.getData();
    <View style=Styles.container>
      <Text> {ReasonReact.string("Hello LambdUp!")} </Text>
      {
        switch (response) {
        | Response(200, data) =>
          <FilteredList
            data={ArrayLabels.of_list(data)}
            onRefresh=(() => ())
          />
        | Error(code, message) => <ErrorMessage code message />
        | _ => <ErrorMessage code=400 message="Cannot load data!" />
        }
      }
    </View>;
  },
};