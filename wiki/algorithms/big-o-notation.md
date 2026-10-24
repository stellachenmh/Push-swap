# Big O Notation

> Sources: GeeksforGeeks (Sanchhaya Education Private Limited), "Big O Notation", Last Updated 28 Mar 2026
> Raw: [big O notation](../../raw/algorithms/2026-10-24-big-o-notation.md)
> Updated: 2026-10-24

## Overview

Big O notation describes the time or space complexity of algorithms. It expresses an **upper bound** of an algorithm's complexity: the asymptotic behavior (order of growth of time or space in terms of input size), not the exact value. It is mainly used with the **worst-case scenario**, and is a way to compare the efficiency of different algorithms or data structures.

## Definition

Given two functions f(n) and g(n), f(n) is **O(g(n))** if there exist constants c > 0 and n₀ ≥ 0 such that:

```
f(n) <= c * g(n)   for all n >= n₀
```

In simpler terms, f(n) is O(g(n)) if f(n) grows no faster than c·g(n) for all n ≥ n₀, where c and n₀ are constants.

## Finding Big O of an Expression

Quick rules:

1. Ignore the lower-order terms; consider only the highest-order term.
2. Ignore the constant attached to the highest-order term.

| Expression | After dropping lower-order terms | After dropping the constant | Big O |
|---|---|---|---|
| 3n² + 2n + 1000 log n + 5000 | 3n² | n² | O(n²) |
| 3n³ + 2n² + 5n + 1 | 3n³ | n³ | O(n³) |

## Properties

| Property | Statement | Example |
|---|---|---|
| Reflexivity | f(n) = O(f(n)) | f(n) = n² → f(n) = O(n²) |
| Transitivity | f(n) = O(g(n)) and g(n) = O(h(n)) ⇒ f(n) = O(h(n)) | n² = O(n³), n³ = O(n⁴) ⇒ n² = O(n⁴) |
| Constant factor | c·f(n) = O(g(n)) if f(n) = O(g(n)) | f(n) = n = O(n²) ⇒ 2·f(n) = O(n²) |
| Sum rule | f(n) + h(n) = O(max(g(n), k(n))) | n² + n³ = O(max(n², n³)) = O(n³) |
| Product rule | f(n)·h(n) = O(g(n)·k(n)) | n · n³ = O(n² · n⁴) = O(n⁶) |
| Composition | f(n) = O(g(n)) ⇒ f(h(n)) = O(g(h(n))) | f(n) = n², h(n) = log n ⇒ (log n)² = O((log n)³) |

## Common Big-O Notations

| Notation | Name | Example |
|---|---|---|
| O(log n) | Logarithmic | Binary search |
| O(n) | Linear | Linear search through an array |
| O(n²) | Quadratic | Bubble sort |
| O(n³) | Cubic | Naive matrix multiplication |
| O(nᵏ) | Polynomial (degree k) | Linear O(n), quadratic O(n²), cubic O(n³) |
| O(2ⁿ) | Exponential | Generating all subsets of a set |
| O(n!) | Factorial | Generating all permutations of an array |

## Growth Comparison

Runtime analysis as input size n increases:

| n | log(n) | n | n·log(n) | n² | 2ⁿ | n! |
|---|---|---|---|---|---|---|
| 10 | 1 | 10 | 10 | 100 | 1024 | 3 628 800 |
| 20 | 2.996 | 20 | 59.9 | 400 | 1 048 576 | 2.432902e+1818 |

## Algorithms by Complexity

| Type | Notation | Example algorithms |
|---|---|---|
| Logarithmic | O(log n) | Binary search |
| Linear | O(n) | Linear search |
| Superlinear | O(n log n) | Heap sort, merge sort |
| Polynomial | O(nᶜ) | Strassen's matrix multiplication, bubble sort, selection sort, insertion sort, bucket sort |
| Exponential | O(cⁿ) | Tower of Hanoi |
| Factorial | O(n!) | Determinant expansion by minors, brute-force TSP search |

## See Also

- [push_swap](../push_swap.md) — uses O(n²), O(n√n), O(n log n) strategy tiers; selects adaptively by measured disorder
- [Binary Radix Sort](binary-radix-sort.md) — LSD/MSD radix sort on two stacks; O(n · b) with b = ceil(log2(n)), i.e. O(n log n)
- [Rank Elements in Array](rank-elements-array.md) — O(N²) simple vs O(N log N) sort-based ranking
