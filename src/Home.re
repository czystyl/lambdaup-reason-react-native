open BsReactNative;

module Styles = {
  open Style;

  let container = style([paddingTop(Pt(30.))]);
};

type state = {
  searchQuery: string,
  response: option(MockedApi.response),
};

type action =
  | ChangeQuery(string)
  | LoadData;

let component = ReasonReact.reducerComponent("Home");

let make = _children => {
  ...component,
  initialState: () => {searchQuery: "", response: None},
  reducer: (action, state) =>
    switch (action) {
    | ChangeQuery(searchQuery) => ReasonReact.Update({...state, searchQuery})
    | LoadData =>
      let response = MockedApi.getData();
      ReasonReact.Update({...state, response: Some(response)});
    },
  didMount: self => self.send(LoadData),
  render: self =>
    <View style=Styles.container>
      <Text> {ReasonReact.string("Hello LambdUp!")} </Text>
      {
        switch (self.state.response) {
        | Some(Response(200, data)) =>
          <FilteredList
            data={ArrayLabels.of_list(data)}
            onRefresh=(() => self.send(LoadData))
          />
        | Some(Error(code, message)) =>
          <ErrorMessage code message onRefresh=(() => self.send(LoadData)) />
        | _ =>
          <ErrorMessage
            code=400
            message="Cannot load data!"
            onRefresh=(() => self.send(LoadData))
          />
        }
      }
    </View>,
};