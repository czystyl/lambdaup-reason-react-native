open BsReactNative;

module Styles = {
  open Style;

  let container =
    style([
      padding(Pt(10.)),
      margin(Pt(10.)),
      borderRadius(5.),
      backgroundColor(Colors.secondary),
      alignItems(Center),
    ]);

  let text = style([color(Colors.light)]);
};

let component = ReasonReact.statelessComponent("ActionButton");

let make = (~onPress, ~text, _children) => {
  ...component,
  render: _self =>
    <TouchableOpacity style=Styles.container onPress>
      <Text style=Styles.text> {ReasonReact.string(text)} </Text>
    </TouchableOpacity>,
};