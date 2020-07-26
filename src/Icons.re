module Asset = {
  let fromFileExtension = fileExtension => {
    switch (fileExtension) {
    | ".jpg" => "jpg.png"
    | ".mov" => "mov.png"
    | ".pdf" => "pdf.png"
    | ".png" => "png.png"
    | ".txt" => "txt.png"
    | ".zip" => "zip.png"
    | _ => "zip.png"
    };
  };
};
