# Binary Radix Sort

> Sources: OpenCode / LongCat 2.5 (AI-generated explanation), 2026-10-21
> Raw: [binary radix sort](../../raw/algorithms/2026-10-21-binary-radix-sort.md)
> Updated: 2026-10-21

## Overview

Binary radix sort is radix sort with a radix of 2: instead of bucketing elements by a decimal digit, it buckets them by one bit at a time. It fits the two-stack push_swap model especially well, because a stable partition by a single bit can be performed with pushes and rotates alone, with no pairwise comparisons. This article covers the least-significant-digit (LSD) form used on stacks, the most-significant-digit (MSD) recursive form used on arrays, and a representation that avoids bitwise operators by storing each rank as a string of bits.

## LSD and MSD

Binary radix sort comes in two flavors:

- **LSD (least-significant-digit)** — process bits from the least-significant to the most-significant, and require every pass to be a **stable** partition by that bit. The classic LSD proof then applies: after processing bits `0..k` the sequence is sorted by those bits, and the final pass leaves it fully sorted. This is the form that maps onto two stacks.
- **MSD (most-significant-digit)** — process bits from the most-significant downward and **recurse on each bucket**. This is essentially quicksort on bits: each level is one `O(n)` partition and there are `ceil(log2(max))` levels, giving `O(n log n)` worst case with no randomization. MSD must recurse on subranges; a single pass over the whole array per bit does not sort, because the next bit's partition would re-mix the groups the previous bit separated.

## The stable partition primitive

The building block is a **stable partition by one bit**: split the sequence into the `bit == 0` group and the `bit == 1` group, keep the original relative order inside each group, and place all zeros before all ones.

With two stacks, suppose the sequence is in stack `A` (top to bottom):

```text
for each of the n elements:
    if bit_of(value, k) == 0:
        pb()          # 0s go to B
    else:
        ra()          # 1s stay in A, rotated to the back

while B is not empty:
    pa()              # 0s come back on top
```

This is stable for two reasons. The 1s that stay in `A` are only ever rotated to the back, so they keep their original relative order at the front of `A`. The 0s pushed onto `B` get reversed, but `pa` pushes them back in reverse again, so they come back in original order. The net result is `[0s in original order][1s in original order]`.

## Representing bits as strings

Testing bit `k` of a rank without bitwise operators means storing the rank as a string of characters, each `'0'` or `'1'`. Build the string most-significant-bit first, padded to a fixed width so every rank has the same number of bits:

```text
function bits_of(rank, width):
    bits = new string of length width
    for i from width-1 down to 0:
        bits[i] = '0' + (rank mod 2)
        rank = rank / 2
    return bits
```

For example, rank 6 with width 3 gives `"110"`. The bit at index `k` (where `k = 0` is the least-significant bit) is the character at position `width - 1 - k`.

The **on-the-fly** version computes the string each time it is needed:

```text
for each element e in A:
    if bits_of(e.rank, width)[width - 1 - k] == '1':
        pb()
    else:
        ra()
```

The **precomputed** version builds one bit string per rank once, then indexes it on every pass:

```text
# Precompute fixed-width bit strings for all ranks
for each element e:
    e.bits = bits_of(e.rank, width)

for k from 0 to width-1:
    for each element e in A (front to back):
        if e.bits[width - 1 - k] == '1':
            pb()
        else:
            ra()
    while B is not empty:
        pa()
```

The on-the-fly form is simpler to write but costs `O(width)` per lookup; the precomputed form is preferred when `width` is not tiny. The trade-off for bit strings in general is `O(width)` time and `O(width)` space per element versus `O(1)` for a bitwise test, so it is a clarity-over-speed choice.

## LSD on two stacks

Putting the pieces together, the two-stack LSD algorithm is:

```text
max_bits = number of bits needed to represent ranks 0 .. n-1

for k from 0 to max_bits-1:
    for i from 0 to n-1:
        if bit_of(a[i], k) == 1:
            pb()
        else:
            ra()
    while b is not empty:
        pa()
```

Two details matter for push_swap:

1. **Sort by rank, not raw value.** The input values are arbitrary integers, so first assign each element its rank (`0..n-1` = its position in the sorted order). That is an `O(n^2)` pass — for each element, count how many are smaller — which is acceptable.
2. **Use ranks' bits, not values' bits.** Only `ceil(log2(n))` bits are needed, and ranks are dense, so there are no gaps.

## Worked example (LSD)

Ranks `[4, 0, 3, 1, 2]`, width 3. Bit strings: `4 = "100"`, `0 = "000"`, `3 = "011"`, `1 = "001"`, `2 = "010"`.

| Pass `k` | 0-group (in order) | 1-group (in order) | Result |
|----------|--------------------|--------------------|--------|
| 0 (LSB) | 4, 0, 2 | 3, 1 | `[4, 0, 2, 3, 1]` |
| 1 | 4, 0, 1 | 2, 3 | `[4, 0, 1, 2, 3]` |
| 2 | 0, 1, 2, 3 | 4 | `[0, 1, 2, 3, 4]` |

The final pass leaves the ranks sorted.

## MSD recursively

The array-based recursive form is:

```text
function msd(elements, hi_bit):
    if hi_bit < 0 or elements is empty:
        return
    zeros = []
    ones = []
    for e in elements:
        if bit_at(e, hi_bit) == 0:
            zeros.append(e)
        else:
            ones.append(e)
    msd(zeros, hi_bit - 1)
    msd(ones, hi_bit - 1)
    result = zeros followed by ones
```

## Complexity and trade-offs

| Variant | Time | Extra space | Stable |
|---------|------|-------------|--------|
| LSD binary radix | `O(n * b)`, `b = ceil(log2(n))` | `O(1)` with two stacks | yes |
| MSD binary radix | `O(n * b)` | `O(n)` buckets or `O(b)` recursion depth | yes if the partition is |

For push_swap, `b` is about 9 for `n = 500`, so the sort is on the order of `2 * n * b` stack operations. That is the main attraction: no pairwise comparisons during the sort, just bit tests and pushes.

## Common gotchas

- **Stability is mandatory.** An unstable partition (for example a plain quicksort-style partition by bit) breaks LSD.
- **Bit direction.** LSD processes the low bit first; MSD processes the high bit first, with recursion.
- **Use dense ranks.** Sorting raw sparse values wastes passes and can need more bits than necessary.
- **Duplicates.** Ranks must be assigned consistently — equal values get equal ranks — or the bit test becomes ambiguous.
- **Reassembly cost.** The `pa` loop is what makes the partition stable; skipping it breaks the algorithm.

## See Also

- [push_swap](../push_swap.md)
