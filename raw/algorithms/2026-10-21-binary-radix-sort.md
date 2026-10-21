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
    if bit_of(value, k) == 0:
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
        if bit_of(a[i], k) == 1:
            pb()
        else:
            ra()
    while b is not empty:
        pa()
```

Two important details for push_swap:

1. Sort by rank, not raw value. push_swap values are arbitrary integers, so first assign each element its rank (0 .. n-1 = position in the sorted order). That is an O(n^2) pass (for each element, count how many are smaller), which is fine.
2. Use ranks' bits, not values' bits. You only need ceil(log2(n)) bits, and ranks are dense, so there are no gaps.

## Representing bits as strings instead of bitwise operators

To test bit k of a rank without bitwise operators, represent the rank as a string of characters, each '0' or '1'. Build the string most-significant-bit first, padded to a fixed width so every rank has the same number of bits:

```text
function bits_of(rank, width):
    bits = new string of length width
    for i from width-1 down to 0:
        bits[i] = '0' + (rank mod 2)
        rank = rank / 2
    return bits
```

For example, rank 6 with width 3 gives "110". The bit at index k (where k = 0 is the least-significant bit) is then the character at position width - 1 - k.

Precompute one bit string per rank once, then each pass indexes the string:

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

The on-the-fly alternative is to call bits_of(e.rank, width) inside the inner loop and read position width - 1 - k. That is simpler to write but costs O(width) per lookup, so the precomputed version is preferred when width is not tiny.

Why bother with bit strings? It avoids bitwise operators entirely, which can help when teaching the algorithm or when working in a context where bit manipulation is awkward. The trade-off is that a bit string costs O(width) time and O(width) space per element, versus O(1) for a bitwise test, so it is a clarity-over-speed choice.

## MSD binary radix sort (recursive, array version)

Process bits from most-significant to least-significant and recurse on each bucket:

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

This is essentially quicksort on bits: each level does one O(n) partition, there are ceil(log2(max)) levels, so O(n log n) worst case with no randomization.

The key difference from LSD: MSD must recurse on subranges. A single pass over the whole array per bit does not sort, because the next bit's partition would re-mix the groups the previous bit separated. That is why the two-stack version above is LSD, not MSD.

## Worked example (LSD)

Ranks [4, 0, 3, 1, 2], width 3. Bit strings: 4 = "100", 0 = "000", 3 = "011", 1 = "001", 2 = "010".

- k = 0 (LSB): 4 -> 0, 0 -> 0, 3 -> 1, 1 -> 1, 2 -> 0. Zeros in order: 4, 0, 2; ones: 3, 1. Result [4, 0, 2, 3, 1].
- k = 1: 4 -> 0, 0 -> 0, 2 -> 1, 3 -> 1, 1 -> 0. Zeros in order: 4, 0, 1; ones: 2, 3. Result [4, 0, 1, 2, 3].
- k = 2: 4 -> 1, 0 -> 0, 1 -> 0, 2 -> 0, 3 -> 0. Zeros in order: 0, 1, 2, 3; ones: 4. Result [0, 1, 2, 3, 4]. Sorted.

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
