# Raytracing

A ray tracer written in C++.

## Requirements

- Docker
- VS Code with the Dev Containers extension (or Zed)

## Getting started

Open the project in its dev container: in VS Code, run **Dev Containers: Reopen in Container**. The first start takes a few minutes.

Then, in the container's terminal:

```sh
cmake --preset unix-debug            # configure (first time only)
cmake --build --preset unix-debug    # compile
./build/unix-debug/raytracer         # run
ctest --preset unix-debug            # test
```

## Tests

Tests use [Catch2](https://github.com/catchorg/Catch2) and run with CTest. We work test-first (TDD):

1. Write a failing test in `tests/`.
2. Write just enough code in `src/` to make it pass.
3. Refactor, keeping the tests green.

A new test file must be added to the `add_executable` list in `tests/CMakeLists.txt`.
