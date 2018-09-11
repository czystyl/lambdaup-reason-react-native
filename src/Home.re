open BsReactNative;

module Styles = {
  open Style;

  let container =
    style([
      alignItems(Center),
      justifyContent(Center),
      paddingTop(Pt(30.)),
    ]);
};

let component = ReasonReact.statelessComponent("Home");

let make = _children => {
  ...component,
  render: _self =>
    <View style=Styles.container>
      <Text> {ReasonReact.string("Hello LambdUp!")} </Text>
    </View>,
};