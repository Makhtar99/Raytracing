# 1. Use a dev container

## Context

Contributors use different machines: macOS, Windows and Linux, on ARM and x86-64. The client's partner studios will too. Each person installing their own compiler and tools leads to bugs that depend on who runs the code.

Alternatives considered: native installs documented in the README, or a package manager such as vcpkg or Conan for dependencies only.

## Decision

We will develop in a dev container defined in `.devcontainer/`, based on `mcr.microsoft.com/devcontainers/cpp:1-ubuntu-24.04`, with CMake, Clang, clangd, clang-format and GDB added in `.devcontainer/Dockerfile`.

## Status

Proposed

## Consequences

- Everyone gets the same Linux, compiler and tools, so a new contributor only needs Docker and an editor.
- Everyone needs Docker, and the first start downloads a large image.
- The container runs Linux on the host's processor: it does not test native macOS or Windows builds, and render times or pixels can still differ between ARM and x86-64.
