open BsReactNative;

module Styles = {
  open Style;
  let container = style([alignItems(Center)]);
  let code =
    style([
      marginTop(Pt(30.)),
      fontSize(Float(30.)),
      color(String("red")),
    ]);
  let text = style([marginBottom(Pt(30.)), color(String("red"))]);
};

let component = ReasonReact.statelessComponent("ErrorMessage");

let make = (~message, ~code, ~onRefresh, _children) => {
  ...component,
  render: _self =>
    <View style=Styles.container>
      <Text style=Styles.code>
        {ReasonReact.string(string_of_int(code))}
      </Text>
      <Text style=Styles.text> {ReasonReact.string(message)} </Text>
      <ActionButton text="Refresh" onPress=onRefresh />
    </View>,
};