# Enumeration (enum) in C

> Sources: GeeksforGeeks (Sanchhaya Education Private Limited), "Enumeration (or enum) in C", Last Updated 18 Jul 2026
> Raw: [enum in c](../../raw/c-programming/2026-11-05-enum-in-c.md)
> Updated: 2026-11-05

## Overview

An **enumeration (enum)** is a user-defined data type in C that assigns meaningful names to a set of integer constants. Enums improve code readability and maintainability by replacing numeric values with descriptive identifiers. They are especially useful for representing states, error codes, menu choices, and file permissions.

The first enum constant is automatically assigned the value `0`, and each subsequent constant is incremented by `1` by default. Enum names follow the standard C variable naming rules, and uppercase is preferred for easy identification.

## Syntax

```c
enum enum_name {
    n1, n2, n3, ...
};
```

where `n1`, `n2`, `n3`, … are identifiers mapped to integer values. By default, `n1` is assigned `0`, `n2` is assigned `1`, and each subsequent name is assigned a value incremented by `1`.

## Create enum variables

After an enum is defined, variables of that type can be declared:

```c
enum_name v;
```

## Initialization

An enum variable can be initialized either with a name defined in the enum definition or directly with its integer value:

```c
#include <stdio.h>

enum direction {
    EAST, NORTH, WEST, SOUTH
};

int main() {
    enum direction dir = NORTH;
    printf("%d\n", dir);   /* outputs 1 */

    dir = 3;
    printf("%d", dir);     /* outputs 3 */
    return 0;
}
```

**Output**

```
1
3
```

Though it is recommended to avoid using integers as enums lose their purpose when integer values are preferred.

## Assign values manually

We can also manually assign desired values to enum names. It is not mandatory to assign all constants; the next name will be automatically assigned a value by incrementing the previous name's value by `1`. Values can be assigned in any order, but they must be integers:

```c
enum enum_name { 
    n1 = val1, n2 = val2, n3, ...
};
```

For example:

```c
#include <stdio.h>

enum enm {
    a = 3, b = 2, c
};

int main() {
    enum enm v1 = a;   /* 3 */
    enum enm v2 = b;   /* 2 */
    enum enm v3 = c;   /* automatically 3 (incremented from last assigned value 2) */
    printf("%d %d %d", v1, v2, v3);
    return 0;
}
```

**Output**

```
3 2 3
```

## Size of enums

An enum definition itself is not allocated any memory — only enum variables are. Enums are typically implemented as `int`, so their size is the same as `int`. Some compilers may use `short int` (or even smaller) to represent enums. The `sizeof` operator can be used to check the size:

```c
#include <stdio.h>

enum direction {
    EAST, NORTH, WEST, SOUTH
};

int main() {
    enum direction dir = NORTH;
    printf("%ld bytes", sizeof(dir));
    return 0;
}
```

**Output**

```
4 bytes
```

## Enum and typedef

The `typedef` keyword can be used to define an alias for an enum, avoiding the need to repeat the `enum` keyword:

```c
#include <stdio.h>

typedef enum direction {
    EAST, NORTH, WEST, SOUTH
} Dirctn;

int main() {
    Dirctn dir = NORTH;
    printf("%d", dir);
    return 0;
}
```

**Output**

```
1
```

In the above program, `typedef` creates a nickname `Dirctn` for the `direction` enum so that it can be directly referred to without the `enum` keyword. It enhances code readability.

## Applications

Enums are extensively used in various real-world programming scenarios:

- **State Representation**: Commonly used to represent different states or modes in state machines, like in game development or process control systems.
- **Error Codes**: Useful for defining a set of related error codes with meaningful names, making code easier to debug and maintain.
- **Menu Choices or User Inputs**: Useful for handling menu options or user input, such as days of the week.
- **File Permissions**: Useful for handling file permissions in an operating system or file management system, with different permission levels such as READ, WRITE, and EXECUTE.

## See Also

- [Variables in C](c-programming/variables-in-c.md) — declaration and initialization of variables, including enum variable creation
- [Data Types in C](c-programming/data-types-in-c.md) — overview of C's built-in and user-defined data types
- [Big O Notation](big-o-notation.md) — not directly related to enum semantics, but enum constants are integer constants and therefore fall under O(1) as atomic values