# Push Swap

> Sources: firecrawl, 2026-10-12
> Raw: [../raw/push-swap-project.md](../raw/push-swap-project.md)
> Updated: 2026-10-12 — when the article's knowledge content last changed. Set to the creation date initially; refresh only on content changes, not typo or formatting fixes.

## Overview

The Push Swap project is a algorithmic sorting challenge where the goal is to sort a stack of integers using a limited set of operations with the minimum number of moves. The project involves implementing various sorting strategies ranging from O(n²) baseline algorithms to O(n log n) efficient strategies, with an adaptive algorithm that selects methods based on the measured disorder of the input.

## Key Concepts

- **Two stacks**: Stack a and stack b, where the goal is to sort stack a in ascending order
- **Operations**: sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr
- **Disorder metric**: A value between 0 and 1 indicating how far the initial stack is from being sorted
- **Sorting strategies**: Simple O(n²), Medium O(n√n), Complex O(n log n), and Custom adaptive algorithm

## Sorting Strategies

1. **Simple algorithm (O(n²))**: Insertion sort, selection sort, or bubble sort adaptations
2. **Medium algorithm (O(n√n))**: Chunk-based or block-based partitioning methods
3. **Complex algorithm (O(n log n))**: Radix sort, merge sort, or quick sort adaptations using the two-stack model
4. **Custom adaptive algorithm**: Selects different internal methods depending on the measured disorder

## Performance Requirements

- For 100 random numbers: <2000 operations (minimum), <1500 (good), <700 (excellent)
- For 500 random numbers: <12000 operations (minimum), <8000 (good), <5500 (excellent)

## See Also

- [Command Line Arguments in C](c-programming/command-line-arguments.md)
- [Big O Notation](algorithms/big-o-notation.md) — formal definition of O-notation, its properties, and common complexity classes referenced by the sorting strategies above
