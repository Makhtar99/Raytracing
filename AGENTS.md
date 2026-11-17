# AGENTS.md

## Commands

Run from the repository root, in the dev container.

```sh
cmake --preset unix-debug          # configure (first time only)
cmake --build --preset unix-debug  # build
./build/unix-debug/raytracer       # run
ctest --preset unix-debug          # test (build first: CTest does not compile)
```

## Architecture decisions

Our architecture decisions are in `docs/adr/`. Read them before changing the build, the tools or the test setup.

- Never go against an accepted ADR. To change a decision, write a new ADR with status Proposed and ask me.
- Never set an ADR to Accepted.
