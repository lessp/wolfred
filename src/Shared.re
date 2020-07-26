module Item = {
  type t = {
    name: string,
    fileExtension: string,
  };

  let make = (~fileExtension, ~name) => {name, fileExtension};
};

module Constants = {
  let searchBarHeight = 56;
  let itemHeight = 48;
  let containerWidth = 640;
  let maxContainerHeight = itemHeight * 12 + searchBarHeight;
};
