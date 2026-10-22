# C++ Structures and Pointers

> Sources: Weber State University CS1410 Textbook, Unknown
> Raw: [Structures and Pointers in C++](../../raw/c-programming/2026-10-22-structures-and-pointers.md)
> Updated: 2026-10-22

## Overview

This article covers using pointers with structures in C++: member selection via the arrow operator (`->`), dereferencing structure pointers, and passing structures to functions by value versus by pointer. The key insight is that pointers avoid copying large structures when passing to/from functions and enable output parameters.

## Member Selection: Dot vs Arrow Operator

The choice between dot (`.`) and arrow (`->`) depends on how the structure is referenced:

| Reference Type | Operator | Example |
|----------------|----------|---------|
| Stack object (direct) | Dot (`.`) | `s1.id` |
| Pointer to stack object | Arrow (`->`) | `sp1->name` |
| Pointer to heap object (`new`) | Arrow (`->`) | `sp2->gpa` |

**Example:**
```cpp
struct student {
    int id;
    string name;
    double gpa;
};

student s1 = { 123, "dilbert", 3.0 };
student* sp1 = &s1;           // pointer to stack object
student* sp2 = new student;   // pointer to heap object

cout << s1.id;      // dot operator
cout << sp1->name;  // arrow operator
cin >> sp2->gpa;    // arrow operator
```

The arrow operator is syntactic sugar: `sp->field` is equivalent to `(*sp).field`. The dot operator has higher precedence than `*`, so parentheses are required: `(*sp).field`.

## Pointer Aliasing and Dereferencing

**Aliasing:** When a pointer holds the address of an existing object (`sp1 = &s1`), the pointer becomes an alias — two names for the same memory location.

**Pointer assignment copies the address, not the object:**
```cpp
student* sp2 = new student { 987, "alice", 4.0 };
student* sp3 = sp2;  // sp3 points to same object as sp2
```

**Dereferencing copies the entire structure:**
```cpp
student s2 = *sp2;  // byte-wise copy of the structure
```
This creates a distinct object with the same field values.

## Passing Structures to Functions

### By Value (Copy Semantics)

```cpp
void print(student temp) { ... }
print(s2);  // copies entire structure to parameter
```
- Entire structure is copied from argument to parameter
- Modifications inside function affect only the copy
- Overhead proportional to structure size

### By Pointer (Reference Semantics)

```cpp
void print(student* temp) {
    cout << temp->id << endl;  // arrow operator required
}
print(&s2);  // pass address, no copy
```
- Only the address (pointer-sized) is copied
- Function parameter aliases the original object
- Modifications through pointer affect the original
- Performance benefit: fixed cost regardless of structure size

### Output Parameters via Pointers

Functions can "return" values through pointer parameters:

```cpp
void read(student* temp) {
    cin >> temp->id >> temp->name >> temp->gpa;
}

student s;
read(&s);  // s is populated by the function
```
- No return statement needed; function has `void` return type
- Caller's object is modified directly through the pointer
- Avoids copying large structures back from the function

## Memory Model Summary

| Operation | Stack Object | Heap Object (`new`) |
|-----------|--------------|---------------------|
| Creation | `student s1;` | `student* sp = new student;` |
| Access field | `s1.field` | `sp->field` |
| Pass to function | `func(s1)` (copy) or `func(&s1)` (pointer) | `func(sp)` (pointer) |
| Aliasing | `student* sp = &s1;` | `student* sp2 = sp1;` |
| Dereference copy | `student s2 = *sp;` | `student s2 = *sp;` |

## See Also

- [Command Line Arguments in C](command-line-arguments.md) — C program input handling
- [Variadic Functions in C](variadic-functions.md) — Functions with variable argument counts