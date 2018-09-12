open BsReactNative;

module Styles = {
  open Style;

  let container =
    style([
      marginHorizontal(Pt(25.)),
      marginVertical(Pt(70.)),
      padding(Pt(10.)),
      borderRadius(10.),
      borderWidth(1.),
      borderColor(Colors.gray),
      flex(1.),
      backgroundColor(Colors.light),
      alignItems(Center),
    ]);

  let name =
    style([padding(Pt(15.)), color(Colors.gray), fontSize(Float(25.))]);

  let button = style([position(Absolute), bottom(Pt(10.))]);

  let image = style([width(Pt(200.))]);
};

let component = ReasonReact.statelessComponent("PersonModal");

let make = (~person: MockedApi.person, ~onClose, _children) => {
  ...component,
  render: _self =>
    <Modal transparent=true animationType=`slide onRequestClose=onClose>
      <View style=Styles.container>
        <Text style=Styles.name>
          {ReasonReact.string(person.firstName)}
        </Text>
        <Text style=Styles.name> {ReasonReact.string(person.lastName)} </Text>
        <Image
          style=Styles.image
          source={
            URI(
              Image.(
                imageURISource(
                  ~uri=
                    "https://api.adorable.io/avatars/285/"
                    ++ string_of_int(person.id),
                  ~width=200.,
                  ~height=200.,
                  (),
                )
              ),
            )
          }
        />
        <View style=Styles.button>
          <ActionButton text="Close" onPress=onClose />
        </View>
      </View>
    </Modal>,
};