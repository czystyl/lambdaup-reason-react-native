open BsReactNative;

let component = ReasonReact.statelessComponent("ErrorMessage");

let make = (~message, ~code, ~onRefresh, _children) => {
  ...component,
  render: _self =>
    <View>
      <Text>
        {ReasonReact.string(string_of_int(code) ++ " - " ++ message)}
      </Text>
      <TouchableOpacity onPress=onRefresh>
        <Text> {ReasonReact.string("Refresh")} </Text>
      </TouchableOpacity>
    </View>,
};