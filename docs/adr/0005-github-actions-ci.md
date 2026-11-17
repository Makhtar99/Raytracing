# 5. Use GitHub Actions for CI

## Context

Contributions from partner studios must not break the build or the tests. Without CI, a broken change is only found after it is merged. CI must run in the same environment as the developers, to avoid "it passes locally but fails in CI".

Alternatives considered: GitLab CI, CircleCI, or a self-hosted runner.

## Decision

We will run a GitHub Actions workflow, `.github/workflows/ci.yml`, on every pull request and every push to `main`. It builds the dev container from `.devcontainer/` with `devcontainers/ci` and runs `make test` inside it.

## Status

Proposed

## Consequences

- Every pull request shows whether it builds and passes the tests, in the same container as local development.
- Building the container image adds a few minutes to each run.
- The project depends on GitHub and on the `devcontainers/ci` action.
