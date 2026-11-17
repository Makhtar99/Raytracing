# 4. Use a Makefile for short commands

## Context

The CMake commands to configure, build, run and test are long and hard to remember. We want short commands, like `npm run build` in JavaScript projects.

Alternatives considered: CMake workflow presets only, shell scripts, or a task runner such as `just`.

## Decision

We will add a `Makefile` at the root with four targets: `make build`, `make run`, `make test` and `make clean`. They call the CMake presets (`unix-debug` by default).

## Status

Proposed

## Consequences

- Four short commands cover daily work, in the container and on Linux or macOS.
- `make` is not available on Windows by default: native Windows users use the presets directly (see README).
- The Makefile is a thin layer over CMake: the build logic stays in CMake.
