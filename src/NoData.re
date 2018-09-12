open BsReactNative;

module Styles = {
  open Style;
  let container = style([alignItems(Center)]);
  let text = style([margin(Pt(30.)), color(Colors.dark)]);
};

let component = ReasonReact.statelessComponent("NoData");

let make = (~onRefresh, _children) => {
  ...component,
  render: _self =>
    <View style=Styles.container>
      <Text style=Styles.text>
        {ReasonReact.string("No Data. Try to refresh!")}
      </Text>
      <ActionButton text="Refresh" onPress=onRefresh />
    </View>,
};