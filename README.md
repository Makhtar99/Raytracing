# Raytracing

A ray tracer written in C++.

## Requirements

- Docker
- VS Code with the Dev Containers extension (or Zed)

## Getting started

Open the project in its dev container: in VS Code, run **Dev Containers: Reopen in Container**. The first start takes a few minutes.

Then, in the container's terminal:

```sh
make build   # configure and compile
make run     # build, then run
make test    # build, then run the tests
make clean   # delete the build folder
```

### Windows without the container

You need Visual Studio 2022 ("Desktop development with C++"), CMake 3.25 or newer and Git. Use the presets:

```powershell
cmake --workflow --preset windows-debug      # configure, build and test
cmake --build --preset windows-debug-run     # build, then run
cmake --build --preset windows-debug-clean   # clean
```

## Tests

Tests use [Catch2](https://github.com/catchorg/Catch2) and run with CTest. We work test-first (TDD). See [CONTRIBUTING.md](CONTRIBUTING.md).

## Project documents

- [CONTRIBUTING.md](CONTRIBUTING.md): set up, workflow and how to submit a change
- [CODE_OF_CONDUCT.md](CODE_OF_CONDUCT.md)
- [docs/adr/](docs/adr/): architecture decision records
- [docs/discovery/](docs/discovery/): discovery report
- [AGENTS.md](AGENTS.md): instructions for AI assistants
