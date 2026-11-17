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
