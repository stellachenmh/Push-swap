# TST - Simple C Testing Framework

> Source: https://github.com/rdentato/tst (GitHub repository README), Remo Dentato
> Collected: 2026-10-24
> Published: Unknown

TST is a modern, lightweight unit testing framework designed specifically for C programs (with full C++ compatibility). Born from the frustration of dealing with complex test frameworks that require extensive build configurations and dependencies, TST provides a simple yet powerful testing solution in a single header file.

## Features

### Core Testing Features

- **Hierarchical Test Organization**: Suites → Cases → Sections
- **Multiple Assertion Types**: `tstcheck`, `tstassert`, `tstexpect`
- **Conditional Execution**: `tstskipif` for runtime test skipping
- **Tag-Based Filtering**: Selective test execution with `+Tag` / `-Tag`
- **Data-Driven Testing**: Automatic iteration over test data arrays
- **Performance Measurement**: Built-in `tstclock` for timing
- **Formatted Messages**: Printf-style assertion messages
- **Rich Diagnostics**: Notes, output blocks, and custom logging

### HTML Report Generator (t2h)

- **Interactive Dashboards**: Click to expand logs and source code
- **Syntax Highlighting**: Color-coded C/C++ source with keyword highlighting
- **Multi-Suite Support**: Consolidate multiple test logs into one report
- **Light/Dark Themes**: Toggle between themes
- **Visual Statistics**: Pie charts and progress bars for pass/fail/skip distribution
- **Source Extraction**: Automatic extraction of test case source code
- **Line Number Mapping**: Links between logs and source code

### Developer Experience

- **No Build System Required**: Direct compilation with any C compiler
- **Self-Documenting**: Test names serve as specifications
- **CI/CD Friendly**: `--report-error` flag for build pipelines
- **Cross-Platform**: Linux, macOS, Windows (WSL, MinGW, MSVC)
- **Zero Dependencies**: Uses only standard C library

## Quick Start

### Installation

Download `tst.h` and copy it to your project:

```text
# Download from GitHub
curl -o tst.h https://raw.githubusercontent.com/rdentato/tst/main/src/tst.h

# Or clone the repository
git clone https://github.com/rdentato/tst.git
cp tst/src/tst.h /path/to/your/project/
```

### Your First Test

```c
#include "tst.h"

tstsuite("My First Test Suite") {
    tstcase("Basic Arithmetic") {
        tstcheck(1 + 1 == 2, "Addition works");
        tstcheck(5 * 4 == 20, "Multiplication works");
    }
    
    tstcase("String Functions") {
        tstcheck(strlen("hello") == 5);
        tstcheck(strcmp("abc", "abc") == 0);
    }
}
```

### Compile and Run

```text
# Compile (no special flags needed)
gcc -o test_example test_example.c

# Run tests
./test_example
```

Output:

```
----- SUIT / test_example.c "My First Test Suite" 2025-11-27 10:30:45
CASE,-- Basic Arithmetic
    4 PASS|  1 + 1 == 2
    5 PASS|  5 * 4 == 20
    `--- 0 FAIL | 2 PASS | 0 SKIP
CASE,-- String Functions
    9 PASS|  strlen("hello") == 5
   10 PASS|  strcmp("abc", "abc") == 0
    `--- 0 FAIL | 2 PASS | 0 SKIP
^^^^^ RSLT \ 0 FAIL | 4 PASS | 0 SKIP 2025-11-27 10:30:45
```

## API Cheat Sheet

```c
// Suite definition
tstsuite("Suite Name") { /* tests */ }

// Test organization
tstcase("Case Name") { /* checks */ }
tstsection("Section %d", val) { /* isolated checks */ }

// Assertions
tstcheck(expr, "message %d", val);    // Continue on failure
tstassert(expr, "critical");          // Abort on failure
tstexpect(expr, "silent on pass");    // Only print failures

// Control flow
tstskipif(condition) { /* skipped tests */ }

// Tags (in tstcase)
tstcase("Test", +RequiresDB, -SlowTests) { }

// Diagnostics
tstnote("Info message %d", val);
tstprintf("Debug output\n");
tstouterr("Block output:") { tstprintf("...\n"); }

// Timing
tstclock("Operation") { /* code */ }
clock_t elapsed = tstelapsed();

// Data-driven
int tstdata[] = {1, 2, 3};
tstsection("Test %d", tstcurdata) { /* runs 3 times */ }
```

## Supported Platforms

| Platform | Compiler | Status |
|---|---|---|
| Linux | gcc, g++, clang | Fully Supported |
| macOS | clang (Apple) | Fully Supported |
| Windows WSL2 | gcc, g++, clang | Fully Supported |
| Windows | MSVC (cl), MinGW | Fully Supported |

### Compiler Requirements

- **C**: C99 or later (C89 compatible with minor limitations)
- **C++**: C++98 or later (automatic `extern "C"` handling)

### Tested Compilers

- GCC 7.0+
- Clang 6.0+
- MSVC 2017+
- MinGW-w64 8.0+

## Project Status

**Current Version**: 0.8.1-beta  
**Status**: Active Development  
**Stability**: Beta (API may change before 1.0 release)

### Roadmap

- 1.0.0 Release with stable API
- JUnit XML output format
- Test coverage integration
- Visual Studio Code extension
- CMake integration helpers

## License

MIT License - Copyright (c) 2023-2025 Remo Dentato.

## Authors

Remo Dentato - Creator and Maintainer (GitHub: @rdentato). Inspired by the simplicity of testing frameworks like Catch2 and doctest.
