open BsReactNative;

module Styles = {
  open Style;

  let container = style([paddingTop(Pt(30.))]);
};

type state = {
  searchQuery: string,
  response: option(MockedApi.response),
  openedModal: option(MockedApi.person),
};

type action =
  | ChangeQuery(string)
  | LoadData
  | OpenModal(MockedApi.person)
  | CloseModal;

let component = ReasonReact.reducerComponent("Home");

let make = _children => {
  ...component,
  initialState: () => {searchQuery: "", response: None, openedModal: None},
  reducer: (action, state) =>
    switch (action) {
    | ChangeQuery(searchQuery) => ReasonReact.Update({...state, searchQuery})
    | LoadData =>
      let response = MockedApi.getData();
      ReasonReact.Update({...state, response: Some(response)});
    | OpenModal(person) =>
      ReasonReact.Update({...state, openedModal: Some(person)})
    | CloseModal => ReasonReact.Update({...state, openedModal: None})
    },
  didMount: self => self.send(LoadData),
  render: self =>
    <View style=Styles.container>
      <Header text="PEOPLE" />
      {
        switch (self.state.response) {
        | Some(Response(200, [])) =>
          <NoData onRefresh=(() => self.send(LoadData)) />
        | Some(Response(200, data)) =>
          <FilteredList
            data
            onRefresh=(() => self.send(LoadData))
            onChangeQuery=(value => self.send(ChangeQuery(value)))
            searchQuery={self.state.searchQuery}
            onItemPress=(person => self.send(OpenModal(person)))
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
      {
        switch (self.state.openedModal) {
        | Some(person) =>
          <PersonModal person onClose=(() => self.send(CloseModal)) />
        | None => ReasonReact.null
        }
      }
    </View>,
};