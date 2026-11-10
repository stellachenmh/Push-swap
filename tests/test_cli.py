#!/usr/bin/env python3
"""Black-box mandatory push_swap regressions."""

import subprocess
import sys


OPS = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"}


def replay(values, operations):
    a = values[:]
    b = []
    for op in operations:
        if op not in OPS:
            raise AssertionError(f"invalid operation: {op!r}")
        if op in ("sa", "ss") and len(a) > 1:
            a[0], a[1] = a[1], a[0]
        if op in ("sb", "ss") and len(b) > 1:
            b[0], b[1] = b[1], b[0]
        if op == "pa" and b:
            a.insert(0, b.pop(0))
        if op == "pb" and a:
            b.insert(0, a.pop(0))
        if op in ("ra", "rr") and a:
            a.append(a.pop(0))
        if op in ("rb", "rr") and b:
            b.append(b.pop(0))
        if op in ("rra", "rrr") and a:
            a.insert(0, a.pop())
        if op in ("rrb", "rrr") and b:
            b.insert(0, b.pop())
    if a != sorted(values) or b:
        raise AssertionError(f"operations did not sort {values}: a={a}, b={b}")


def run(*args):
    return subprocess.run(["./push_swap", *args], capture_output=True, text=True)


def check_sorted(args, values):
    result = run(*args)
    assert result.returncode == 0, (args, result.returncode, result.stderr)
    assert result.stderr == "", (args, result.stderr)
    replay(values, result.stdout.split())
    return result


def main():
    result = check_sorted(("2", "1"), [2, 1])
    assert result.stdout == "sa\n", result.stdout
    for strategy in ("--simple", "--medium", "--complex", "--adaptive"):
        result = check_sorted((strategy, "2", "1"), [2, 1])
        assert result.stdout == "sa\n", (strategy, result.stdout)
    check_sorted(("--simple", "3", "1", "2"), [3, 1, 2])
    for args in (("--simple", "--bench", "3", "1", "2"),
                 ("--bench", "--simple", "3", "1", "2")):
        result = run(*args)
        assert result.returncode == 0, (args, result.stderr)
        assert "[bench] strategy: Simple / O(n^2)\n" in result.stderr
        replay([3, 1, 2], result.stdout.split())

    bench = run("--bench", "--complex", "3", "1", "2")
    assert bench.returncode == 0, (bench.returncode, bench.stderr)
    assert "[bench] disorder: " in bench.stderr, bench.stderr
    assert "[bench] strategy: Complex / O(n log n)\n" in bench.stderr
    assert "[bench] total_ops: " in bench.stderr
    replay([3, 1, 2], bench.stdout.split())

    for invalid in (("nope",), ("2147483648",), ("18446744073709551658",)):
        result = run(*invalid)
        assert result.returncode != 0, (invalid, result.returncode)
        assert result.stdout == "", (invalid, result.stdout)
        assert result.stderr == "Error\n", (invalid, result.stderr)
    print("mandatory CLI regressions passed")


if __name__ == "__main__":
    try:
        main()
    except (AssertionError, OSError) as exc:
        print(exc, file=sys.stderr)
        sys.exit(1)