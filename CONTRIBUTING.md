# Contributing

Thank you for helping. This guide covers everything you need to build the project, run the tests and submit a change.

## Set up

1. Install Docker and VS Code with the Dev Containers extension (or Zed).
2. Clone the repository and open it in its dev container: **Dev Containers: Reopen in Container**.
3. In the container's terminal, check that everything works:

   ```sh
   make run    # prints Hello, World!
   make test   # all tests pass
   ```

On Windows, clone the repository inside WSL, not in a Windows folder, so that line endings stay correct.

## Commands

| Command | What it does |
|---|---|
| `make build` | Configure and compile |
| `make run` | Build, then run |
| `make test` | Build, then run the tests |
| `make clean` | Delete the build folder |

## Work test-first (TDD)

1. Write a failing test in `tests/`.
2. Write just enough code in `src/` to make it pass.
3. Refactor, keeping the tests green.

Add each new test file to the `add_executable` list in `tests/CMakeLists.txt`. Code goes in `src/`, in the `raytracer_core` library, so the tests can use it.

## Architecture decisions

Decisions about the build, the tools and the tests are recorded in `docs/adr/`. Read them before changing any of these.

To change a decision, don't edit an accepted ADR: open a pull request with a new ADR, numbered after the last one, with status **Proposed**. The maintainer accepts it after review.

## Submit a change

1. Create a branch from `main`.
2. Make your change, with tests.
3. Run `make test`.
4. Open a pull request and fill in the template. CI builds the project and runs the tests in the dev container: it must pass before merging.

## Licence

By contributing, you agree that your contributions are licensed under the [MIT licence](LICENSE).

## Code of conduct

By taking part, you agree to follow our [code of conduct](CODE_OF_CONDUCT.md).
