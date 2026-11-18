# 2. Use CMake and CTest to build and test

## Context

The project must build the same way on every platform, and the tests must run with one command. C++ has no single standard build tool.

Alternatives considered: Meson, Bazel, or hand-written Makefiles.

## Decision

We will describe the build with CMake (3.25 or newer) and its presets in `CMakePresets.json`: `unix-debug`, `unix-release` and `windows`. The code lives in a `raytracer_core` library shared by the program and the tests. Tests run with CTest.

## Status

Accepted

## Consequences

- CMake is the most common build tool in C++ projects, so contributors are likely to know it, and IDEs support it.
- One more language to learn, with a syntax that is easy to get wrong.
- Presets give each platform a short, named configuration instead of long command lines.
