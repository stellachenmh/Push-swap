# Doxygen C++ Documentation

> Sources: GeeksforGeeks, 2024-07-05
> Raw: [Doxygen C++ documentation](../../raw/c-programming/2024-07-05-doxygen-cpp-documentation.md)
> Updated: 2026-10-20

## Overview

Doxygen is the popular C++ tool for generating documentation from specially formatted comments embedded in source code. Documentation aids code comprehension, maintenance, and collaboration — especially in large projects spanning thousands of lines, functions, classes, and multiple files. Doxygen parses structured comments to automatically produce HTML or LaTeX documentation, promoting readability, reusability, and teamwork.

## Why Document C++ Code

- Provides a clear understanding of what a piece of code does
- Specifies input parameters, working, and return types
- Explains the logic or algorithm used in a function or class
- Helps other developers use all functions, classes, and structures correctly
- Aids maintaining and updating code through clear explanations of functionality
- Facilitates collaboration via a shared understanding of the codebase
- Helps identify and fix bugs more efficiently

## Generating Documentation with Doxygen

Doxygen generates documentation from specially formatted comments within source code. The workflow:

1. **Install Doxygen** — download and install it from its official website.
2. **Configure Doxygen** — create a configuration file using the `doxygen -g` command and customize it as needed.
3. **Run Doxygen** — execute the `doxygen` command to generate documentation in HTML or LaTeX format.

## Doxygen Comment Structure

Doxygen comments come in two styles:

- C-style: `/** ... */`
- C++-style: `/// ...`

Each line within the comment block starts with an asterisk `*`, except for the closing line.

## Tags

Tags begin with the `@` symbol followed by the tag name. Commonly used tags:

- `@brief` — brief description of the function or class; a concise summary typically used for functions, classes, or methods
- `@param` — describes a function parameter, specified along with its name and a description
- `@return` — describes the return value, including conditions or constraints associated with it
- `@details` — detailed description: in-depth explanation of the entity's behavior, usage, edge cases, and additional information
- `@example` — links to an external file containing example code, useful for comprehensive usage examples without cluttering the main documentation

Brief descriptions are short summaries, typically one or two sentences. Detailed descriptions provide comprehensive explanations including usage examples and edge cases.

## Worked Example

The source demonstrates a documented recursive factorial function:

```cpp
/**
 * @brief Calculates the factorial of a number.
 *
 * This function computes the factorial of a given
 * non-negative integer. It uses a recursive approach to
 * calculate the factorial.
 *
 * @param n The number for which the factorial is to be
 * calculated.
 *
 * @return The factorial of the number.
 *
 * @details
 * The factorial of a non-negative integer n is the product
 * of all positive integers less than or equal to n. For
 * example, the factorial of 5 is 5 * 4 * 3 * 2 * 1 = 120.
 * This function uses recursion to compute the factorial.
 *
 *  @example example.cpp
 *
 * @usage
 * int result = factorial(5); // result will be 120
 */
int factorial(int n)
{
    // Base case: factorial of 0 is 1
    if (n == 0)
        return 1;

    // Recursive case: n * factorial(n - 1)
    return n * factorial(n - 1);
}
```

The program computes the factorial of 5 via `factorial(n)` in `main`, producing:

```
Factorial of 5 is: 120
```
