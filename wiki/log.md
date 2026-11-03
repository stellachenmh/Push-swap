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

## [2026-10-24] ingest | TST — Simple C Testing Framework

- Disposition: New
- Raw: raw/c-programming/2026-10-24-tst-c-testing-framework.md
- Updated: c-programming/tst-c-testing-framework.md

## [2026-10-24] lint | 10 issues found, 0 auto-fixed

- No new issues from the TST ingest; all 10 suspects pre-existing (big-o-notation.md scientific-notation tokenization artifact; rank-elements-array.md, variadic-functions.md, push_swap.md).

## [2026-10-24] ingest | Bucket Sort

- Disposition: New
- Raw: raw/algorithms/2026-10-24-bucket-sort.md
- Updated: algorithms/bucket-sort.md; algorithms/big-o-notation.md (added See Also to bucket sort); algorithms/binary-radix-sort.md (added See Also to bucket sort)

## [2026-10-24] lint | 10 issues found, 0 auto-fixed

- No new issues from the Bucket Sort ingest; all 10 suspects pre-existing (big-o-notation.md scientific-notation tokenization artifact; rank-elements-array.md, variadic-functions.md, push_swap.md).

## [2026-10-24] edit | Bucket Sort — two-bucket variant

- Rewrote algorithms/bucket-sort.md for exactly 2 buckets: pseudocode (no C code), worked example on [0.78, 0.17, 0.39, 0.26, 0.94, 0.68] with split point 0.5, three mermaid diagrams (distribution, per-bucket insertion sort, gathering), and a two-bucket complexity analysis (O(n²) worst/even-split with insertion sort; O(n log n) with merge/heap sort per bucket; O(n) space).
- Adjusted wiki/index.md summary to match the two-bucket analysis.

## [2026-10-24] lint | 16 issues found, 0 auto-fixed

- 6 new suspects in bucket-sort.md (0.5 split point; 1.56, 0.34, 0.52, 1.88, 1.36 products) — all legitimate derived values: the 0.5 split is the stated adaptation rule (floor(2x) < 1 ⇔ x < 0.5), and the products are table-derived from raw elements (0.78, 0.17, 0.39, 0.26, 0.94, 0.68 all appear verbatim in raw).
- 10 pre-existing suspects elsewhere unchanged.

## [2026-10-24] edit | Bucket Sort — chunk-based O(n√n) push_swap variant

- Rewrote algorithms/bucket-sort.md for integers with √n chunks: pseudocode (no C code), worked example on n=16 integers [13, 3, 9, ...], table mapping bucket ops to push_swap ops (pb/pa/ra/rb/rrb/sa/sb), three mermaid diagrams (chunk distribution, xychart growth O(n√n) vs O(n²) vs O(n log n)), and a complexity derivation showing m × O(c²) = √n × O(n) = O(n√n) with n=100 concrete numbers (~1000–1500 ops, matching push_swap's <2000 minimum for 100 numbers).
- Adjusted wiki/index.md summary to match the chunk-based O(n√n) analysis.

## [2026-10-24] lint | 14 issues found, 0 auto-fixed

- Fixed evidence error: push_swap-project.md raw link now uses correct depth (../../raw/) from wiki/algorithms/.
- bucket-sort.md suspects all legitimate: "Chunk-based or block-based partitioning methods" combines two adjacent raw bullets (raw/push-swap-project.md lines 393, 399); 1500/2000 verbatim from raw (lines 718, 716); 1000 is a labeled approximate derived estimate.
- No new issues from the bucket sort rewrite.

## [2026-10-24] edit | Bucket Sort — fix mermaid diagram parsing

- Fixed Parse error on line 13: changed edge labels in the distribution flowchart to quoted strings, e.g., A0 -->|"rank in [0,3]; pb"| C0, to avoid mermaid parser issues with commas and bracket notation inside edge labels.
- Also corrected the O(n√n) xychart data point for O(n log n) at n=400 (3458 instead of 3200) to match n*log2(n) calculation.
- Raised y-axis max to 100,000,000 to accommodate the O(n²) curve point at n=10000.
