# Binary Radix Sort

> Source: AI-generated explanation (OpenCode / LongCat 2.5), 2026-10-21
> Collected: 2026-10-21
> Published: Unknown

Binary radix sort is radix sort with a radix of 2: instead of bucketing elements by decimal digit, it buckets them by a single bit at a time. It comes in two flavors, and the right one depends on whether you are sorting an array in memory or shuffling two stacks around. The version that fits the two-stack push_swap model is the least-significant-digit (LSD) form, where each pass is a stable partition by one bit.

## LSD binary radix sort

Process bits from least-significant to most-significant, and make every pass a stable partition by that bit. If every pass is stable, the classic LSD proof applies: after processing bits 0 through k the sequence is sorted by those bits, and the final pass leaves it fully sorted.

The primitive you need is a stable partition by one bit: split the sequence into the bit == 0 group and the bit == 1 group, keeping the original relative order inside each group, with all zeros before all ones.

### Stable partition with two stacks

Suppose the sequence is in stack A (top to bottom). Do:

```text
for each of the n elements:
    if ((value >> k) & 1) == 0:
        pb()          # 0s go to B
    else:
        ra()          # 1s stay in A, rotated to the back

while B is not empty:
    pa()              # 0s come back on top
```

Why it is stable:

- The 1s that stay in A are only ever rotated to the back, so they keep their original relative order at the front of A.
- The 0s pushed onto B get reversed, but pa pushes them back in reverse again, so they come back in original order.
- Net result: [0s in original order][1s in original order] — exactly the stable partition you wanted.

### Full algorithm

```text
max_bits = number of bits needed to represent ranks 0 .. n-1

for k from 0 to max_bits-1:
    for i from 0 to n-1:
        if ((a[i].rank >> k) & 1) == 0:
            pb()
        else:
            ra()
    while b is not empty:
        pa()
```

Two important details for push_swap:

1. Sort by rank, not raw value. push_swap values are arbitrary integers, so first assign each element its rank (0 .. n-1 = position in the sorted order). That is an O(n^2) pass (for each element, count how many are smaller), which is fine.
2. Use ranks' bits, not values' bits. You only need ceil(log2(n)) bits, and ranks are dense, so there are no gaps.

## Reading a bit with bitwise operators

To test bit k of a rank (where k = 0 is the least-significant bit), shift the rank right by k and then mask with 1:

```text
bit = (rank >> k) & 1
```

- rank >> k moves bit k down into the units place, dividing by 2^k and discarding the remainder.
- & 1 keeps only the lowest bit, so the result is exactly 0 or 1.

For rank 6 = binary 110:

- bit 0: (6 >> 0) & 1 = 110 & 001 = 0
- bit 1: (6 >> 1) & 1 = 011 & 001 = 1
- bit 2: (6 >> 2) & 1 = 001 & 001 = 1

The division and modulo equivalent is (rank / 2^k) mod 2, but shift-and-mask is the idiomatic bitwise test and costs a constant number of machine instructions.

## MSD binary radix sort (recursive, array version)

Process bits from most-significant to least-significant and recurse on each bucket:

```text
function msd(elements, hi_bit):
    if hi_bit < 0 or elements is empty:
        return
    zeros = []
    ones = []
    for e in elements:
        if ((e >> hi_bit) & 1) == 0:
            zeros.append(e)
        else:
            ones.append(e)
    msd(zeros, hi_bit - 1)
    msd(ones, hi_bit - 1)
    result = zeros followed by ones
```

This is essentially quicksort on bits: each level does one O(n) partition, there are ceil(log2(max)) levels, so O(n log n) worst case with no randomization.

The key difference from LSD: MSD must recurse on subranges. A single pass over the whole array per bit does not sort, because the next bit's partition would re-mix the groups the previous bit separated. That is why the two-stack version above is LSD, not MSD.

## Worked example (LSD on two stacks)

Start with stack A (top to bottom) = [19, 2, 34, 8, 5, 21, 0] and B empty. Sort by rank. The sorted values are [0, 2, 5, 8, 19, 21, 34], so each value's rank is its index in that order. Width = ceil(log2 7) = 3 bits.

| value | rank | 3-bit binary | bit 0 | bit 1 | bit 2 |
|-------|------|--------------|-------|-------|-------|
| 19    | 4    | 100          | 0     | 0     | 1     |
| 2     | 1    | 001          | 1     | 0     | 0     |
| 34    | 6    | 110          | 0     | 1     | 1     |
| 8     | 3    | 011          | 1     | 1     | 0     |
| 5     | 2    | 010          | 0     | 1     | 0     |
| 21    | 5    | 101          | 1     | 0     | 1     |
| 0     | 0    | 000          | 0     | 0     | 0     |

### Pass k = 0 (bit 0)

Push elements whose bit 0 == 0 to B (pb); elements whose bit 0 == 1 stay in A and are rotated to the back (ra). Draining B back onto A with pa puts the 0s on top.

| step | op | element (rank, bit0) | A | B |
|------|----|----------------------|---|---|
| start | - | - | [19, 2, 34, 8, 5, 21, 0] | [] |
| 1 | pb | 19 (4, 0) | [2, 34, 8, 5, 21, 0] | [19] |
| 2 | ra | 2 (1, 1) | [34, 8, 5, 21, 0, 2] | [19] |
| 3 | pb | 34 (6, 0) | [8, 5, 21, 0, 2] | [34, 19] |
| 4 | ra | 8 (3, 1) | [5, 21, 0, 2, 8] | [34, 19] |
| 5 | pb | 5 (2, 0) | [21, 0, 2, 8] | [5, 34, 19] |
| 6 | ra | 21 (5, 1) | [0, 2, 8, 21] | [5, 34, 19] |
| 7 | pb | 0 (0, 0) | [2, 8, 21] | [0, 5, 34, 19] |
| pa x4 | pa | drain B onto A | [19, 34, 5, 0, 2, 8, 21] | [] |

### Pass k = 1 (bit 1)

Same procedure, now testing bit 1 of each rank.

| step | op | element (rank, bit1) | A | B |
|------|----|----------------------|---|---|
| start | - | - | [19, 34, 5, 0, 2, 8, 21] | [] |
| 1 | pb | 19 (4, 0) | [34, 5, 0, 2, 8, 21] | [19] |
| 2 | ra | 34 (6, 1) | [5, 0, 2, 8, 21, 34] | [19] |
| 3 | ra | 5 (2, 1) | [0, 2, 8, 21, 34, 5] | [19] |
| 4 | pb | 0 (0, 0) | [2, 8, 21, 34, 5] | [0, 19] |
| 5 | pb | 2 (1, 0) | [8, 21, 34, 5] | [2, 0, 19] |
| 6 | ra | 8 (3, 1) | [21, 34, 5, 8] | [2, 0, 19] |
| 7 | pb | 21 (5, 0) | [34, 5, 8] | [21, 2, 0, 19] |
| pa x4 | pa | drain B onto A | [19, 0, 2, 21, 34, 5, 8] | [] |

### Pass k = 2 (bit 2)

Same procedure, now testing bit 2 of each rank. This is the last pass (3 bits), so the result is fully sorted.

| step | op | element (rank, bit2) | A | B |
|------|----|----------------------|---|---|
| start | - | - | [19, 0, 2, 21, 34, 5, 8] | [] |
| 1 | ra | 19 (4, 1) | [0, 2, 21, 34, 5, 8, 19] | [] |
| 2 | pb | 0 (0, 0) | [2, 21, 34, 5, 8, 19] | [0] |
| 3 | pb | 2 (1, 0) | [21, 34, 5, 8, 19] | [2, 0] |
| 4 | ra | 21 (5, 1) | [34, 5, 8, 19, 21] | [2, 0] |
| 5 | ra | 34 (6, 1) | [5, 8, 19, 21, 34] | [2, 0] |
| 6 | pb | 5 (2, 0) | [8, 19, 21, 34] | [5, 2, 0] |
| 7 | pb | 8 (3, 0) | [19, 21, 34] | [8, 5, 2, 0] |
| pa x4 | pa | drain B onto A | [0, 2, 5, 8, 19, 21, 34] | [] |

## Complexity

- LSD binary radix: O(n * b) time, b = ceil(log2(n)), O(1) extra space with two stacks, stable.
- MSD binary radix: O(n * b) time, O(n) space for buckets or O(b) recursion depth, stable if the partition is.

For push_swap, b is about 9 for n = 500, so it is on the order of 2 * n * b stack operations. That is the main attraction: no pairwise comparisons during the sort, just bit tests and pushes.

## Common gotchas

- Stability is mandatory. If you use an unstable partition (for example a plain quicksort-style partition by bit), LSD gives wrong results.
- Bit direction. LSD processes the low bit first. MSD processes the high bit first, with recursion.
- Use dense ranks. Sorting raw sparse values wastes passes and can even need more bits than necessary.
- Empty and duplicate handling. With duplicates, ranks must be assigned consistently (equal values get equal ranks) or the bit test becomes ambiguous.
- Reassembly cost. The pa loop is what makes it stable; skipping it breaks the algorithm.
