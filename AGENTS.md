# AGENTS.md

## Commands

Run from the repository root, in the dev container.

```sh
make build   # configure and compile
make run     # build, then run
make test    # build, then run the tests
make clean   # delete the build folder
```

On Windows without the container, use the presets (see README).

## Architecture decisions

Our architecture decisions are in `docs/adr/`. Read them before changing the build, the tools or the test setup.

- Never go against an accepted ADR. To change a decision, write a new ADR with status Proposed and ask me.
- Never set an ADR to Accepted.

## Contributing

See `CONTRIBUTING.md` for the workflow (TDD, ADRs, pull requests).

## How we work

- Test-driven development: write a failing test first, then only enough code to make it pass.
- Expected values in tests come from the maths, not from running the code. If a test fails, ask me before changing what it expects.
- One small step at a time. Do only what I ask for, nothing more.
- Keep the C++ simple. No advanced features unless I ask for them.
- Do not build or run anything on the host. The commands above run in the dev container.

## Source layout

New classes go in the folder of their concept, under `src/`, and their tests in the matching folder under `tests/`. Includes start from `src/`, for example `#include "math/vector.h"`.
