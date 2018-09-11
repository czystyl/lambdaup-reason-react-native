open BsReactNative;

let component = ReasonReact.statelessComponent("ActionButton");

let make = (~onPress, ~text, _children) => {
  ...component,
  render: _self =>
    <TouchableOpacity onPress>
      <Text> {ReasonReact.string(text)} </Text>
    </TouchableOpacity>,
};