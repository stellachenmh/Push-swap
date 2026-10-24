# Big O Notation

> Source: GeeksforGeeks (Sanchhaya Education Private Limited), "Big O Notation", Last Updated 28 Mar, 2026
> Collected: 2026-10-24
> Published: 2026-03-28

Big O notation is used to describe the time or space complexity of algorithms. Big-O is a way to express an upper bound of an algorithm's time or space complexity.

- Describes the asymptotic behavior (order of growth of time or space in terms of input size) of a function, not its exact value.
- Can be used to compare the efficiency of different algorithms or data structures.
- It provides an upper limit on the time taken by an algorithm in terms of the size of the input. We mainly consider the worst case scenario of the algorithm to find its time complexity in terms of Big O.

## Big O Definition

Given two functions f(n) and g(n), we say that f(n) is O(g(n)) if there exist constants c > 0 and n₀ >= 0 such that f(n) <= c*g(n) for all n >= n₀.

In simpler terms, f(n) is O(g(n)) if f(n) grows no faster than c*g(n) for all n >= n₀ where c and n₀ are constants.

## A Quick Way to Find Big O of an Expression

- Ignore the lower order terms and consider only highest order term.
- Ignore the constant associated with the highest order term.

Example 1: f(n) = 3n² + 2n + 1000 log n + 5000
- After ignoring lower order terms, we get the highest order term as 3n²
- After ignoring the constant 3, we get n²
- Therefore the Big O value of this expression is O(n²)

Example 2: f(n) = 3n³ + 2n² + 5n + 1
- Dominant term: 3n³
- Order of growth: Cubic (n³)
- Big O notation: O(n³)

## Properties of Big O Notation

1. **Reflexivity**: For any function f(n), f(n) = O(f(n)). Example: f(n) = n², then f(n) = O(n²).

2. **Transitivity**: If f(n) = O(g(n)) and g(n) = O(h(n)), then f(n) = O(h(n)). Example: f(n) = n², g(n) = n³, h(n) = n⁴; therefore f(n) = O(g(n)) and g(n) = O(h(n)), so by transitivity f(n) = O(h(n)).

3. **Constant factor**: For any constant c > 0 and functions f(n) and g(n), if f(n) = O(g(n)), then c·f(n) = O(g(n)). Example: f(n) = n, g(n) = n²; f(n) = O(g(n)), therefore 2·f(n) = O(g(n)).

4. **Sum rule**: If f(n) = O(g(n)) and h(n) = O(k(n)), then f(n) + h(n) = O(max(g(n), k(n))). When combining complexities, only the largest term dominates. Example: f(n) = n², h(n) = n³; f(n) + h(n) = O(max(n², n³)) = O(n³).

5. **Product rule**: If f(n) = O(g(n)) and h(n) = O(k(n)), then f(n) · h(n) = O(g(n) · k(n)). Example: f(n) = n, g(n) = n², h(n) = n³, k(n) = n⁴; therefore f(n) · h(n) = O(g(n) · k(n)) = O(n⁶).

6. **Composition rule**: If f(n) = O(g(n)), then f(h(n)) = O(g(h(n))). Example: f(n) = n², g(n) = n³, h(n) = log n; f(h(n)) = O(g(h(n))), therefore (log n)² = O((log n)³).

## Common Big-O Notations

Big-O notation describes the upper bound of the complexity in the worst-case scenario.

1. **Linear time: O(n)** — running time grows linearly with input size. Example: linear search traversing an array.
2. **Logarithmic time: O(log n)** — running time is proportional to the logarithm of input size. Example: binary search.
3. **Quadratic time: O(n²)** — running time is proportional to the square of input size. Example: bubble sort.
4. **Cubic time: O(n³)** — running time is proportional to the cube of input size. Example: naive matrix multiplication.
5. **Polynomial time: O(nᵏ)** — k is a constant representing the degree. Examples: linear O(n), quadratic O(n²), cubic O(n³).
6. **Exponential time: O(2ⁿ)** — running time doubles with each addition to the input. Example: generating all subsets of a set.
7. **Factorial time: O(n!)** — running time grows factorially. Example: generating all permutations of an array.

## Mathematical Examples of Runtime Analysis

| n | log(n) | n | n * log(n) | n² | 2ⁿ | n! |
|---|---|---|---|---|---|---|
| 10 | 1 | 10 | 10 | 100 | 1024 | 3628800 |
| 20 | 2.996 | 20 | 59.9 | 400 | 1048576 | 2.432902e+1818 |

## Algorithmic Examples of Runtime Analysis

| Type | Notation | Example Algorithms |
|---|---|---|
| Logarithmic | O(log n) | Binary Search |
| Linear | O(n) | Linear Search |
| Superlinear | O(n log n) | Heap Sort, Merge Sort |
| Polynomial | O(nᶜ) | Strassen's Matrix Multiplication, Bubble Sort, Selection Sort, Insertion Sort, Bucket Sort |
| Exponential | O(cⁿ) | Tower of Hanoi |
| Factorial | O(n!) | Determinant Expansion by Minors, Brute force Search algorithm for Traveling Salesman Problem |
