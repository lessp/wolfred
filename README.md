# Wolfred

An [Alfred](https://www.alfredapp.com/)-like starting point for Revery which lets you search for files in your Desktop-directory.

Currently there's no status-bar/tray-support.

## Screenshot

<img src="./docs/example-image.png" width="640" />

## Prerequisites

See the [requirements for building Revery](https://github.com/revery-ui/revery/wiki/Building-&-Installing)

## Getting started

```
# Install & build dependencies
esy
```

> **NOTE:** The first build will take a while - building the OCaml compiler and dependencies takes time! Subsequent builds, though, should be very fast.

Once built, the application binary will be in the `_build/install/default/bin` - you can run it like:

- `_build/install/default/bin/Wolfred`

or using esy with the script specified in [package.json](package.json#L8):

- `esy run`

## Releasing

To create packages for distribution, follow these steps:

- `npm install -g revery-packager`

From the project-folder, run:

- `revery-packager`

Once complete, there will be application packages available in the `_release` folder.

## License

[MIT License](LICENSE)

## Credits

Icons made by <a href="https://www.flaticon.com/authors/dimitry-miroliubov" title="Dimitry Miroliubov">Dimitry Miroliubov</a> from <a href="https://www.flaticon.com/" title="Flaticon"> www.flaticon.com</a>
