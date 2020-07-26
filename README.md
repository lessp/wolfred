# Wolfred

An [Alfred](https://www.alfredapp.com/)-like starting point for Revery which lets you search for files in your Desktop-directory.

Currently there's no status-bar/tray-support.

## Prerequisites

See the [requirements for building Revery](https://github.com/revery-ui/revery/wiki/Building-&-Installing)

## Getting started

```
# Install & build dependencies
esy
```

> **NOTE:** The first build will take a while - building the OCaml compiler and dependencies takes time! Subsequent builds, though, should be very fast.

Once built, the application binary will be in the `_build/install/default/bin` - you can run it like:

- `_build/install/default/bin/App`

or using esy with the script specified in [package.json](package.json#L8):

- `esy run`

## Information

A Revery application also needs the following

- [`package.json`](package.json) - [esy configuration](https://esy.sh/docs/en/configuration.html) - lists the Reason/OCaml dependencies.
- `dune` / `dune-project` - build configuration files used by [Dune](https://dune.readthedocs.io/en/latest/).
- `.opam` - metadata used by the build system.

## Releasing

To create packages for distribution, follow these steps:

- `npm install -g revery-packager`

From the `revery-quick-start` folder, run:

- `revery-packager`

Once complete, there will be application packages available in the `_release` folder.

## License

[MIT License](LICENSE)

Icons made by <a href="https://www.flaticon.com/authors/dimitry-miroliubov" title="Dimitry Miroliubov">Dimitry Miroliubov</a> from <a href="https://www.flaticon.com/" title="Flaticon"> www.flaticon.com</a>
