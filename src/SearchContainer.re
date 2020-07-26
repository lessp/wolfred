open Revery;
open Revery.UI;
open Revery.UI.Components;

/* Helper Functions */
let matches = (query, {name, _}: Shared.Item.t) =>
  String.toLower(name) |> String.contains(~substring=String.toLower(query));

let increment = (itemLength, currentIndex) =>
  if (itemLength > 0 && currentIndex + 1 <= itemLength) {
    currentIndex + 1;
  } else {
    currentIndex;
  };

let decrement = (itemLength, currentIndex) =>
  if (itemLength > 0 && currentIndex - 1 >= 0) {
    currentIndex - 1;
  } else {
    currentIndex;
  };

/* Component */
type state = {
  query: string,
  items: list(Shared.Item.t),
  matchingItems: list(Shared.Item.t),
  containerHeight: int,
  itemIndexSelected: option(int),
};

type action =
  | SetSelectedItem(option(int))
  | SetContainerHeight(int)
  | SetQuery(string)
  | SetMatchingItems(list(Shared.Item.t));

let initialState = items => {
  query: "",
  items,
  matchingItems: [],
  containerHeight: Shared.Constants.searchBarHeight,
  itemIndexSelected: None,
};

let reducer = (action, state) => {
  switch (action) {
  | SetSelectedItem(selectedItem) => {
      ...state,
      itemIndexSelected: selectedItem,
    }
  | SetQuery(query) => {...state, query}
  | SetMatchingItems(matchingItems) => {...state, matchingItems}
  | SetContainerHeight(containerHeight) => {...state, containerHeight}
  };
};

let%component make = (~window: Window.t, ~items, ()) => {
  let%hook (state, dispatch) =
    Hooks.reducer(~initialState=initialState(items), reducer);

  let handleQueryUpdate = (newValue, _) => {
    /* Get matching items */
    let matchingItems =
      newValue != "" ? state.items |> List.filter(~f=matches(newValue)) : [];

    /* Calculate new window-height based on num matching items */
    let containerHeight =
      List.length(matchingItems)
      * Shared.Constants.itemHeight
      + Shared.Constants.searchBarHeight;

    dispatch(SetQuery(newValue));
    dispatch(SetMatchingItems(matchingItems));
    /* Reset any selectedItemIndex on query-change */
    dispatch(
      SetSelectedItem(List.isEmpty(matchingItems) ? None : Some(0)),
    );
    dispatch(SetContainerHeight(containerHeight));
  };

  let handleKeyDown = ({keycode, _}: NodeEvents.keyEventParams) => {
    switch (state.matchingItems, state.itemIndexSelected) {
    | ([], _) => dispatch(SetSelectedItem(None))
    | (items, selectedItem) =>
      let selectedItemIndex = selectedItem |> Option.withDefault(~default=0);

      switch (Key.Keycode.toString(keycode)) {
      | "Down" =>
        dispatch(
          SetSelectedItem(
            Some(increment(List.length(items) - 1, selectedItemIndex)),
          ),
        )
      | "Up" =>
        dispatch(
          SetSelectedItem(
            Some(decrement(List.length(items) - 1, selectedItemIndex)),
          ),
        )
      | "Return" =>
        let fileThatReturnWasPressedOn =
          state.matchingItems
          |> List.getAt(~index=selectedItemIndex)
          |> Option.map(~f=({name, _}: Shared.Item.t) => name)
          |> Option.withDefault(~default="None");

        Console.log("Pressed return on: " ++ fileThatReturnWasPressedOn);
      | _ => ()
      };
    };
  };

  let%hook () =
    Hooks.effect(
      OnMountAndIf((!=), state.containerHeight),
      () => {
        window
        |> Window.setSize(
             ~height=state.containerHeight,
             ~width=Shared.Constants.containerWidth,
           );

        None;
      },
    );

  let hasMatchingItems = List.length(state.matchingItems) > 0;

  <View
    style=Style.[
      position(`Absolute),
      top(0),
      left(0),
      right(0),
      bottom(0),
      height(state.containerHeight),
    ]>
    <Input
      autofocus=true
      fontFamily=Theme.Typography.bold
      fontSize=20.
      fontWeight=Font.Weight.Medium
      onKeyDown=handleKeyDown
      onChange=handleQueryUpdate
      value={state.query}
      placeholderColor={Color.hex(Theme.silentText)}
      placeholder="Search..."
      style=Style.[
        alignSelf(`Stretch),
        alignItems(`Center),
        height(Shared.Constants.searchBarHeight),
        backgroundColor(Color.hex(Theme.dimWhite)),
        border(~width=0, ~color=Colors.transparentWhite),
        width(Shared.Constants.containerWidth),
      ]
    />
    {hasMatchingItems
       ? <View>
           <View
             style=Style.[
               height(1),
               width(Shared.Constants.containerWidth),
               backgroundColor(Color.hex(Theme.dimGrey)),
             ]
           />
           <ScrollView
             style=Style.[flexGrow(1), height(state.containerHeight)]>
             <Column>
               {state.matchingItems
                |> List.indexedMap(~f=(index, item: Shared.Item.t) => {
                     let isActive =
                       switch (state.itemIndexSelected) {
                       | Some(selectedIndex) => selectedIndex == index
                       | None => false
                       };

                     <SearchItem active=isActive item />;
                   })
                |> React.listToElement}
             </Column>
           </ScrollView>
         </View>
       : React.empty}
  </View>;
};
