open BsReactNative;

let component = ReasonReact.statelessComponent("NoData");

let make = (~onRefresh, _children) => {
  ...component,
  render: _self =>
    <View>
      <Text> {ReasonReact.string("No Data. Try to refresh!")} </Text>
      <ActionButton text="Refresh" onPress=onRefresh />
    </View>,
};