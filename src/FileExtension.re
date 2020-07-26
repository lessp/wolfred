open Revery;

let fromPath = path => {
  path
  |> Fpath.of_string
  |> Result.withDefault(~default=Fpath.v("/~"))
  |> Fpath.get_ext;
};
