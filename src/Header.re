open BsReactNative;

module Styles = {
  open Style;

  let container =
    style([
      padding(Pt(10.)),
      justifyContent(Center),
      alignItems(Center),
      borderBottomWidth(1.),
      borderBottomColor(Colors.light),
      marginBottom(Pt(10.)),
    ]);

  let text = style([fontSize(Float(25.)), color(Colors.primary)]);
};

let component = ReasonReact.statelessComponent("Header");

let make = (~text, _children) => {
  ...component,
  render: _self =>
    <View style=Styles.container>
      <Text style=Styles.text> {ReasonReact.string(text)} </Text>
    </View>,
};