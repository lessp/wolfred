open Revery;
open Revery.UI;
open Revery.UI.Components;

let fromFileExtension = fileExtension => {
  let iconPath =
    switch (fileExtension) {
    | ".jpg" => "jpg.png"
    | ".mov" => "mov.png"
    | ".pdf" => "pdf.png"
    | ".png" => "png.png"
    | ".txt" => "txt.png"
    | ".zip" => "zip.png"
    | _ => "zip.png"
    };

  <Image
    src={`File(iconPath)}
    height=24
    width=24
    style=Style.[marginRight(12)]
  />;
};
