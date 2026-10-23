# Why Binary Radix Sort Is O(n log n)

> Source: AI-generated explanation (OpenCode / MiMo-V2.6 Flash), 2026-10-23
> Collected: 2026-10-23
> Published: Unknown

Binary radix sort sorts by inspecting one bit position at a time (LSB to MSB), doing a stable partition into "bit = 0" and "bit = 1" groups each pass. In push_swap, values are index-compressed to [0, n), so the numbers only need ceil(log2(n)) bits.

## The calculation

Cost of one pass: you touch every element once — read 1 bit, increment a counter, write the element to a new position. That's c*n work for a small constant c (about 3 operations per element).

    T(1 pass) = c*n          -> Theta(n)

Number of passes: one per bit. With values in [0, n), the maximum value is n - 1, which fits in ceil(log2(n)) bits:

| n | range | bits needed | passes |
|---|---|---|---|
| 16 | 0–15 | 4 | 4 |
| 1024 | 0–1023 | 10 | 10 |
| 4096 | 0–4095 | 12 | 12 |
| 100 000 | 0–99 999 | 17 | 17 |

    passes = ceil(log2(n))

Total:

    T(n) = passes x T(1 pass)
         = ceil(log2(n)) x c*n
         = c*n*log2(n) + c*n          (the +c*n is the last partial bit)
         = Theta(n log n)

## Concrete numbers (n = 1024)

- Radix: 10 passes x 1024 elements x ~3 ops = ~30 720 operations
- Bubble sort: n^2 = 1 048 576 comparisons (~34x worse)
- Merge/quick sort: n*log2(n) = 10 240 comparisons, but each comparison is an expensive tree-node/pointer/swap operation, while radix's inner loop is just a bit test and a memcpy.

## Why it can't be O(n)

If the value range were fixed (e.g. raw 32-bit ints), then passes = 32 = a constant, giving Theta(n). But here the bit-width grows with n (log2(n)), so it's genuinely n log n, not linear.

## Why log n passes is the floor (information theory)

There are n! possible orderings, so you need log2(n!) ~ n*log2(n) bits of information to determine the answer. Each pass inspects n bits and reveals at most n bits of information about the ordering, so you need at least:

    n*log2(n) / n = log2(n) passes (minimum)

Binary radix sort on compressed indices therefore exactly meets the information-theoretic bound — same asymptotic class as comparison sorts, but with a much smaller constant because it never builds a comparison tree.

## Growth chart data

Operations vs n for binary radix sort on indices in [0, n):

- n values: 128, 512, 1024, 4096, 16384
- single pass = n: 128, 512, 1024, 4096, 16384
- full sort = n * log2(n): 896, 4608, 10240, 49152, 229376

The gap between the lines is the log2(n) multiplier — it grows very slowly (7, 9, 10, 12, 14 passes), which is exactly why radix sort stays fast in practice even though it is technically O(n log n).
