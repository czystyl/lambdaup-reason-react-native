open BsReactNative;

module Styles = {
  open Style;

  let itemContainer =
    style([
      padding(Pt(15.)),
      borderBottomWidth(1.),
      borderBottomColor(Colors.light),
    ]);

  let input =
    style([
      padding(Pt(10.)),
      margin(Pt(10.)),
      borderRadius(5.),
      borderWidth(1.),
      borderColor(Colors.gray),
    ]);
};

let renderItem = onItemPress =>
  FlatList.renderItem((event: FlatList.renderBag(MockedApi.person)) =>
    <TouchableOpacity onPress={() => onItemPress(event.item)}>
      <View style=Styles.itemContainer>
        <Text>
          {
            ReasonReact.string(
              event.item.firstName ++ " " ++ event.item.lastName,
            )
          }
        </Text>
      </View>
    </TouchableOpacity>
  );

let component = ReasonReact.statelessComponent("FilteredList");

let make =
    (
      ~data: list(MockedApi.person),
      ~onRefresh,
      ~onChangeQuery,
      ~searchQuery,
      ~onItemPress,
      _children,
    ) => {
  ...component,
  render: _children => {
    let filteredData =
      data
      |> List.filter(
           item =>
             item.firstName
             ++ item.lastName
             |> Js.String.includes(searchQuery): MockedApi.person => bool,
         );
    <View>
      <TextInput
        style=Styles.input
        onChangeText=onChangeQuery
        value=searchQuery
        placeholder="search"
      />
      <FlatList
        data={Array.of_list(filteredData)}
        renderItem={renderItem(onItemPress)}
        keyExtractor={(event, _index) => string_of_int(event.id)}
        refreshing=false
        onRefresh
      />
    </View>;
  },
};