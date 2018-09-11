open BsReactNative;

module Styles = {
  open Style;
  let container = style([alignItems(Center)]);
  let text = style([margin(Pt(30.)), color(Colors.dark)]);
};

let component = ReasonReact.statelessComponent("ErrorMessage");

let make = (~message, ~code, ~onRefresh, _children) => {
  ...component,
  render: _self =>
    <View style=Styles.container>
      <Text style=Styles.text>
        {ReasonReact.string(string_of_int(code) ++ " - " ++ message)}
      </Text>
      <ActionButton text="Refresh" onPress=onRefresh />
    </View>,
};