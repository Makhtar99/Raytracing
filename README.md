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

Tests use [Catch2](https://github.com/catchorg/Catch2) and run with CTest. We work test-first (TDD):

1. Write a failing test in `tests/`.
2. Write just enough code in `src/` to make it pass.
3. Refactor, keeping the tests green.

A new test file must be added to the `add_executable` list in `tests/CMakeLists.txt`.
