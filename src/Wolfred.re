open Revery;
open Revery.UI;
open Revery.UI.Components;

let desktopFiles =
  Dir.User.desktop
  |> Option.withDefault(~default=Dir.home)
  |> Fp.toString
  |> Sys.readdir
  |> Array.map(~f=fileName =>
       Shared.Item.make(
         ~name=fileName,
         ~fileExtension=FileExtension.fromPath(fileName),
       )
     )
  |> Array.toList;

let init = app => {
  Revery.App.initConsole();

  let window =
    App.createWindow(
      app,
      "Wolfred",
      ~createOptions=
        WindowCreateOptions.create(
          ~x=`Centered,
          ~y=`Absolute(320),
          ~backgroundColor=Color.hex(Theme.dimWhite),
          ~resizable=false,
          // There's currently only support for hiding the titlebar for macOS,
          // on the other platforms, lets fall back to un-decorated
          ~decorated={
            Environment.os == Environment.Mac ? true : false;
          },
          // Hidden only works for Mac currently, but doesn't have an effect
          // on the other platforms
          ~titlebarStyle=Hidden,
          ~width=Shared.Constants.containerWidth,
          ~minimumHeight=Shared.Constants.searchBarHeight,
          ~height=Shared.Constants.searchBarHeight,
          (),
        ),
    );

  let _startEventLoop = Revery_Lwt.startEventLoop();

  let _update: Revery.UI.renderFunction =
    UI.start(window, <SearchContainer window items=desktopFiles />);

  ();
};

App.start(init);
