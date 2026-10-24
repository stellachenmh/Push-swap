## [2026-10-12] ingest | push_swap

- Disposition: Update
- Raw: raw/push-swap-project.md
- Updated: push_swap

## [2026-10-14] ingest | Command Line Arguments in C

- Disposition: New
- Raw: raw/c-programming/2026-10-14-command-line-arguments-in-c.md
- Updated: c-programming/command-line-arguments.md

## [2026-10-14] ingest | Variadic Functions in C

- Disposition: New
- Raw: raw/c-programming/2026-10-14-variadic-functions-in-c.md
- Updated: c-programming/variadic-functions.md

## [2026-10-14] lint | 6 issues found, 0 auto-fixed

## [2026-10-20] ingest | Doxygen C++ Documentation

- Disposition: New
- Raw: raw/c-programming/2024-07-05-doxygen-cpp-documentation.md
- Updated: c-programming/doxygen-cpp-documentation.md

## [2026-10-20] lint | 6 issues found, 0 auto-fixed

- All 6 fidelity suspects pre-existing in variadic-functions.md and push_swap.md; none in the new article.

## [2026-10-20] ingest | Git Feature Branch Workflow

- Disposition: New
- Raw: raw/git/feature-branch-workflow.md
- Updated: git/feature-branch-workflow.md

## [2026-10-20] lint | 6 issues found, 0 auto-fixed

- Same 6 pre-existing fidelity suspects in variadic-functions.md and push_swap.md; none in the new article.

## [2026-10-20] edit | Git Feature Branch Workflow

- Bash language tags on all fenced code blocks; added three mermaid gitGraph diagrams (lifecycle, Mary/Bill PR flow, parallel Mary+John work)
- Lint re-run: 6 pre-existing fidelity suspects, 0 new issues

## [2026-10-20] lint | 6 issues found, 0 auto-fixed

- Verification run after diagram addition; all 6 suspects pre-existing.

## [2026-10-20] ingest | Merging Locally Without a Pull Request

- Disposition: Update
- Raw: raw/git/merge-to-main-local.md
- Updated: git/feature-branch-workflow.md

## [2026-10-21] ingest | Binary Radix Sort

- Disposition: New
- Raw: raw/algorithms/2026-10-21-binary-radix-sort.md
- Updated: algorithms/binary-radix-sort.md

## [2026-10-21] lint | 6 issues found, 0 auto-fixed

- All 6 fidelity suspects pre-existing in variadic-functions.md and push_swap.md; none in the new article.

## [2026-10-23] edit | Binary Radix Sort

- Replaced the bit-string representation with the bitwise `(rank >> k) & 1` shift-and-mask test and a clear explanation; fixed an inverted push/rotate rule in the LSD pseudocode so bit == 0 is pushed to B and bit == 1 is rotated, keeping 0s before 1s.
- Added a worked example on buckets A = [19, 2, 34, 8, 5, 21, 0] with mermaid diagrams for the value-to-rank-to-binary mapping and each of the three LSD passes (pb/ra/pa), grounded by an updated raw.
- Raw updated to match: bitwise-operator section and the expanded worked-example tables.

## [2026-10-22] ingest | Rank Elements in Array

- Disposition: New
- Raw: raw/algorithms/2026-10-22-rank-elements-array.md
- Updated: algorithms/rank-elements-array.md

## [2026-10-22] ingest | Structures and Pointers in C++

- Disposition: New
- Raw: raw/c-programming/2026-10-22-structures-and-pointers.md
- Updated: c-programming/structures-and-pointers.md

## [2026-10-23] ingest | Binary Radix Sort (complexity analysis)

- Disposition: Update
- Raw: raw/algorithms/2026-10-23-binary-radix-sort-complexity.md
- Expanded "Complexity and trade-offs" with a "Why it is O(n log n)" subsection: pass-cost/passes derivation, bit-width table, n = 1024 comparison vs bubble/merge/quick, fixed-range (32-bit) caveat, information-theoretic lower bound, and a mermaid xychart of operations vs n.

## [2026-10-23] lint | 9 issues found, 0 auto-fixed

- All 9 fidelity suspects pre-existing (rank-elements-array.md, variadic-functions.md, push_swap.md); none in binary-radix-sort.md.

## [2026-10-24] ingest | Big O Notation

- Disposition: New
- Raw: raw/algorithms/2026-10-24-big-o-notation.md
- Updated: algorithms/big-o-notation.md; algorithms/binary-radix-sort.md (added GFG as corroborating source for the O(n log n) claim); push_swap.md (added See Also cross-reference to Big O definition)

## [2026-10-24] lint | 10 issues found, 0 auto-fixed

- 1 new suspect in big-o-notation.md ("2.43290") — false positive: the wiki value 2.432902e+1818 matches raw verbatim; scientific-notation tokenization split the token.
- 9 pre-existing suspects (rank-elements-array.md, variadic-functions.md, push_swap.md).
