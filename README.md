*This project has been created as part of the 42 curriculum by slau, stelchen.*

# push_swap

## Description

`push_swap` generates operations that sort integer values on stack A using two
stacks and the push_swap operation set. Values are ranked before sorting, so
the algorithms work consistently for any valid `int` input. The program also
supports selectable strategies and an optional benchmark report on stderr.

## Contributions

- **slau (Simon Lau):** main program flow, Simple and Complex sorting,
  operation output/statistics, and benchmark reporting.
- **stelchen (Stella Chen):** argument parsing, Medium sorting, shared sorting
  helpers, and algorithm documentation.
- Both learners contributed to integration and regression testing.

## Instructions

Build with `make`, then run `./push_swap [flags] <integer>...`. Available
strategy flags are `--simple`, `--medium`, `--complex`, and `--adaptive`;
adaptive is the default. Add `--bench` to print the initial disorder, chosen
strategy, and operation counts to stderr while leaving the operation stream on
stdout. For example:

```sh
make
./push_swap --bench --complex 4 67 3 87 23
```

Use `make test` to build and run the mandatory tests. With no arguments the
program prints nothing; invalid arguments print `Error` to stderr.

## Algorithms

All complexity claims below count generated push_swap operations. Rank storage
and the two stack buffers use O(n) auxiliary space.

- **Simple — O(n²):** repeatedly locate the minimum remaining rank, rotate it
  to the top of A, and push it to B. Sort the final three values directly and
  return the extracted values to A. This is the low-disorder baseline.
- **Medium — O(n√n):** move ranks to B in progressively advancing ranges sized
  proportional to √n, then extract the largest ranks back to A. Scanning the
  remaining stack across √n ranges yields the O(n√n) operation bound.
- **Complex — O(n log n):** binary radix sorting processes each rank bit once;
  each pass scans and redistributes at most n values, with O(log n) passes.
- **Adaptive:** uses the inversion-based disorder metric to select a strategy:
  below 0.2 it selects Simple, from 0.2 up to (but not including) 0.5 it
  selects Medium, and from 0.5 onward it selects Complex. These thresholds
  route nearly sorted inputs to the baseline and reserve radix sorting for
  inputs with many inversions.

For stacks of up to three values, each selector uses the direct minimal small
sort; this preserves correct behavior for every selector without changing its
large-input strategy.

## Resources

- The mandatory requirements and operation definitions: `raw/push-swap-project.md`.
- Donald E. Knuth, *The Art of Computer Programming, Volume 3: Sorting and Searching*.
- AI assistance was used to diagnose defects and implement/review mandatory
  parser and CLI handling, strategy selection/sorting, benchmark/error output,
  memory cleanup, regression tests, and this documentation. The bonus checker
  was not part of this work. Changes were validated with the project tests and
  operation-replay checks.
