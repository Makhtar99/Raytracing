# 6. One folder per concept

## Context

All our code sits in one flat `src/` folder, and all our tests in one flat `tests/` folder. A ray tracer will grow many classes: vectors, rays, shapes, materials, cameras, images. In one folder, it becomes hard to find a class and to know which test file belongs to it. Moving one file now is cheap, moving twenty later is not.

## Decision

Each concept gets its own folder under `src/`, named after the domain. `Vector` lives in `src/math/`.

Tests mirror this layout: the tests for `src/math/vector.cpp` are in `tests/math/test_vector.cpp`.

Includes always start from `src/`, for example `#include "math/vector.h"`.

A folder is created with its first class, not before.

## Status

Accepted

## Consequences

- A class and its tests are found from their concept.
- An include line shows where a header lives.
- Moving a file means updating the CMake lists, the includes and the matching test.
- Someone has to decide which concept a class belongs to, and a folder with one file can look like overkill at first.
- Nothing separates a folder's public headers from its private ones.

## Left out for now

- **Namespaces**, such as `raytracer::Vector`. Worth it when two classes want the same name, or when partner studios use our code inside theirs.
- **One library per folder.** Worth it when we want the build to stop one folder depending on another, or when build times grow.
- **A separate `include/` folder.** Worth it when we ship the ray tracer as a library and must separate public headers from private ones.
