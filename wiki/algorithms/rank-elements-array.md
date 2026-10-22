# Rank Elements in Array

> Sources: GeeksforGeeks, 2024-03-29
> Raw: [Rank of all elements in an array](../../raw/algorithms/2026-10-22-rank-elements-array.md)
> Updated: 2026-10-22

## Overview

Element ranking assigns each element in an array a rank from 1 to N based on its sorted position. For distinct elements, the rank is simply 1 plus the count of smaller elements. When duplicates exist, all equal elements receive the same rank — the arithmetic mean of the consecutive ranks they would occupy. This is known as "fractional ranking" or "competition ranking (1, 2.5, 2.5, 4)".

## Definition

Given an array `A` of length `N`, the rank of element `A[i]` is:

- `r` = number of elements strictly less than `A[i]` plus 1
- `s` = number of elements equal to `A[i]`
- Rank = `r + 0.5 * (s - 1)`

This formula derives from averaging `s` consecutive ranks starting at `r`: `(r + (r+1) + ... + (r+s-1)) / s = r + (s-1)/2`.

## Examples

| Input | Output |
|-------|--------|
| `[20, 30, 10]` | `[2.0, 3.0, 1.0]` |
| `[10, 12, 15, 12, 10, 25, 12]` | `[1.5, 4.0, 6.0, 4.0, 1.5, 7.0, 4.0]` |
| `[1, 2, 5, 2, 1, 60, 3]` | `[1.5, 3.5, 6.0, 3.5, 1.5, 7.0, 5.0]` |

For the second example: value 10 appears twice (ranks 1 and 2 → average 1.5), value 12 appears three times (ranks 3, 4, 5 → average 4.0), value 15 appears once (rank 6), value 25 appears once (rank 7).

## Method I: Simple O(N²)

For each element, count elements smaller than it (`r`) and equal to it (`s`) by scanning the entire array.

**Algorithm:**
```
function rankify(A):
    N = length of A
    R = array of size N
    for i in 0..N-1:
        r = 1, s = 1
        for j in 0..N-1:
            if j != i and A[j] < A[i]: r += 1
            if j != i and A[j] == A[i]: s += 1
        R[i] = r + 0.5 * (s - 1)
    return R
```

**Complexity:** O(N²) time, O(N) auxiliary space.

Implementations provided in C++, Java, Python, C#, JavaScript, PHP.

## Method II: Efficient O(N log N)

Sort an array of (value, original_index) tuples. Equal values become adjacent, allowing rank assignment in a single pass.

**Algorithm:**
```
function rankify_improved(A):
    N = length of A
    T = [(A[i], i) for i in 0..N-1]  // (value, original_index)
    sort T by value ascending
    R = array of size N
    rank = 1
    i = 0
    while i < N:
        j = i
        while j < N-1 and T[j].value == T[j+1].value:
            j += 1
        m = j - i + 1  // count of equal elements
        for k in 0..m-1:
            idx = T[i+k].original_index
            R[idx] = rank + (m - 1) * 0.5
        rank += m
        i += m
    return R
```

**Complexity:** O(N log N) time (dominated by sort), O(N) auxiliary space.

Implementations provided in C++, Java, Python, C#, JavaScript.

## See Also

- [Binary Radix Sort](binary-radix-sort.md) — another sorting-adjacent algorithm with linearithmic complexity
- [push_swap](../push_swap.md) — stack-based sorting with limited operations