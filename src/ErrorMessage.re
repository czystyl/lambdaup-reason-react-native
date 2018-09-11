open BsReactNative;

let component = ReasonReact.statelessComponent("ErrorMessage");

let make = (~message, ~code, _children) => {
  ...component,
  render: _self =>
    <View>
      <Text>
        {ReasonReact.string(string_of_int(code) ++ " - " ++ message)}
      </Text>
    </View>,
};