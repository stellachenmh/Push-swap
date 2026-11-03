# TST — Simple C Testing Framework

> Sources: Remo Dentato / rdentato, "TST — Simple C Testing Framework" (GitHub repository README), 2026-10-24
> Raw: [TST - Simple C Testing Framework](../../raw/c-programming/2026-10-24-tst-c-testing-framework.md)
> Updated: 2026-10-24

## Overview

TST is a lightweight, single-header unit testing framework for C (with full C++ compatibility) created by Remo Dentato. It requires zero dependencies — just include `tst.h` — and is designed to avoid the extensive build configuration of heavier frameworks. It is distributed under the MIT License (Copyright 2023–2025 Remo Dentato), current version 0.8.1-beta, in active development.

## Core Features

- **Hierarchical organization**: tests nest as suites → cases → sections.
- **Assertions**: `tstcheck(expr, ...)` (continue on failure), `tstassert(expr, ...)` (abort on failure), `tstexpect(expr, ...)` (silent on pass).
- **Control flow**: `tstskipif(condition)` for conditional skipping.
- **Tag-based filtering**: cases carry `+Tag` / `-Tag` labels; the test binary accepts `+Tag` / `-Tag` / `--list` / `--report-error` flags for CI/CD use.
- **Data-driven tests**: arrays named `tstdata` drive repeated `tstsection` executions via `tstcurdata`.
- **Timing**: `tstclock("label") { ... }` measures CPU time; `tstelapsed()` reports it.
- **Diagnostics**: `tstnote`, `tstprintf`, `tstouterr` blocks.
- **HTML reports**: the companion `t2h` utility converts test logs into interactive HTML dashboards with source-code extraction and light/dark themes.
- **Shell testing**: `tst.sh` is a bash library producing TST-formatted output for shell-script tests.

## Quick Start

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

Compile with any C compiler (C99+) and run — no special flags, no build system:

```text
gcc -o test_example test_example.c
./test_example
```

## Supported Platforms

| Platform | Compilers |
|---|---|
| Linux | gcc, g++, clang |
| macOS | clang (Apple) |
| Windows WSL2 | gcc, g++, clang |
| Windows | MSVC (cl), MinGW |

Compiler requirements: C99 or later (C89 with minor limitations); C++98 or later with automatic `extern "C"` handling. Tested with GCC 7.0+, Clang 6.0+, MSVC 2017+, MinGW-w64 8.0+.

## Project Status

- Version: 0.8.1-beta
- Status: Active development
- Stability: Beta — API may change before the 1.0 release
- Roadmap: stable 1.0.0 API, JUnit XML output, test coverage integration, VS Code extension, CMake helpers

## See Also

- None yet — consider linking here from any future push_swap testing article.
