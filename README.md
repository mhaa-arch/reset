# MHAA Reset Core

Use `Reset` to inspect recorded boot causes, test individual flags or consume the record when the source supports clearing. An optional request facet can request reset for the represented domain.

Use `causes()` to observe the record, or bind `ReadClear&` to take and acknowledge it. Supply reset requests for the same domain explicitly.

## Use in an application

Add this repository's `include/` and the matching `reset-contract/include/` to the C++11 include path. Include `<reset/reset.hpp>` and supply a live implementation of the matching Contract. The Core borrows it. In a future device composition, Devices will select the concrete Adapter and wire it to the Core.

- [Technical guide](docs/index.md)
- [Core usage](docs/api.md)
- [Portability and limits](docs/compatibility.md)
- [Worked example and build commands](docs/examples.md)
- [MIT License](LICENSE)

## Generate the API reference

Use Doxygen 1.18.0. From this repository root, create `build/` if it does not exist, then run `doxygen Doxyfile`.

```sh
mkdir -p build
doxygen Doxyfile
```

On PowerShell, use `New-Item -ItemType Directory -Force build` for the first command. Open `build/docs/html/index.html`. Mermaid diagrams render in a browser with access to the Mermaid CDN. GitHub Pages publication runs on published releases and on manual dispatches from `main` once Pages is enabled.
