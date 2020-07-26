open Revery;
open Revery.UI;
open Revery.UI.Components;

let make = (~active, ~item: Shared.Item.t, ()) =>
  <View
    style=Style.[
      backgroundColor(Color.hex(active ? Theme.lightBlue : Theme.dimWhite)),
      height(Shared.Constants.itemHeight),
      justifyContent(`Center),
      paddingHorizontal(8),
    ]>
    <Row>
      <Text
        fontFamily=Theme.Typography.bold
        fontWeight=Font.Weight.Medium
        style=Style.[
          color(active ? Colors.white : Colors.black),
          flexGrow(1),
        ]
        text={item.name}
      />
      <Image
        src={`File(Icons.Asset.fromFileExtension(item.fileExtension))}
        height=24
        width=24
        style=Style.[marginRight(12)]
      />
    </Row>
  </View>;
