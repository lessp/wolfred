open Revery;

module Item = {
  type t = {
    name: string,
    iconAsset: string,
  };

  let make = (~iconAsset, ~name) => {name, iconAsset};
};

module Constants = {
  let searchBarHeight = 56;
  let itemHeight = 48;
  let maxContainerHeight = itemHeight * 12 + searchBarHeight;
};
