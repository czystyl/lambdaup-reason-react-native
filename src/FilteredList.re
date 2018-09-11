open BsReactNative;

module Styles = {
  open Style;

  let itemContainer = style([padding(Pt(10.))]);
};

let renderItem =
  FlatList.renderItem((event: FlatList.renderBag(MockedApi.person)) =>
    <View style=Styles.itemContainer>
      <Text> {ReasonReact.string(event.item.firstName)} </Text>
    </View>
  );

let component = ReasonReact.statelessComponent("FilteredList");

let make = (~data: array(MockedApi.person), ~onRefresh, _children) => {
  ...component,
  render: _children =>
    <View>
      <FlatList
        data
        renderItem
        keyExtractor={(event, _index) => string_of_int(event.id)}
        refreshing=false
        onRefresh
      />
    </View>,
};