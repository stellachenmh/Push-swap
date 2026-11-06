*This project has been created as part of the 42 curriculum by stelchen.*

## Description

The **Libft** project is the foundational step in the 42 curriculum, designed to create a custom, reusable C library containing essential utility functions. The primary goal of this project is to gain a thorough understanding of low-level C programming, dynamic memory management, pointer manipulation, and data structure implementations by recreating standard C library (`libc`) functions as well as additional utility functions and linked list manipulations. All three parts—standard C library functions, additional utility functions, and linked list utilities—are mandatory components of the project requirements. Once compiled into a static archive (`libft.a`), this library serves as a fundamental toolkit to be utilized across subsequent projects throughout the 42 syllabus.

### Detailed Description of Library Functions

#### Part 1 — Libc Functions (Mandatory)

* **`ft_isalpha`**  
  Checks if the passed character is an alphabetic character (either uppercase or lowercase).  
  Returns 1 if the character matches, or 0 otherwise.

* **`ft_isdigit`**  
  Checks if the passed character is a decimal digit character (0 through 9).  
  Returns 1 if the character matches, or 0 otherwise.

* **`ft_isalnum`**  
  Checks if the passed character is alphanumeric (either an alphabetic letter or a digit).  
  Returns 1 if the character matches, or 0 otherwise.

* **`ft_isascii`**  
  Checks if the passed character fits into the ASCII character set (values between 0 and 127).  
  Returns 1 if the character matches, or 0 otherwise.

* **`ft_isprint`**  
  Checks if the passed character is any printable character, including space.  
  Returns 1 if the character matches, or 0 otherwise.

* **`ft_strlen`**  
  Computes and returns the length of the string pointed to by `s`.  
  Iterates through the string until reaching the terminating null character (`\0`).

* **`ft_memset`**  
  Fills the first `n` bytes of the memory area pointed to by `s` with the constant byte `c`.  
  Returns a pointer to the memory area `s`.

* **`ft_bzero`**  
  Erases the data in the `n` bytes of the memory starting at the location pointed to by `s` by writing zeros (`\0`) to that area.  
  Does not return a value.

* **`ft_memcpy`**  
  Copies `n` bytes from memory area `src` to memory area `dest`.  
  The memory areas must not overlap; returns a pointer to `dest`.

* **`ft_memmove`**  
  Copies `n` bytes from memory area `src` to memory area `dest` handling overlapping memory regions safely.  
  Returns a pointer to `dest`.

* **`ft_strlcpy`**  
  Copies up to `size - 1` characters from the NUL-terminated string `src` to `dest`, NUL-terminating the result.  
  Returns the total length of the string `src` it tried to create.

* **`ft_strlcat`**  
  Appends the NUL-terminated string `src` to the end of `dest`, placing at most `size - strlen(dest) - 1` characters and NUL-terminating.  
  Returns the initial length of `dest` plus the length of `src`.

* **`ft_toupper`**  
  Converts a lowercase letter to its corresponding uppercase letter.  
  If the character is not a lowercase letter, returns the character unchanged.

* **`ft_tolower`**  
  Converts an uppercase letter to its corresponding lowercase letter.  
  If the character is not an uppercase letter, returns the character unchanged.

* **`ft_strchr`**  
  Locates the first occurrence of the character `c` (converted to a char) in the string `s`.  
  Returns a pointer to the matched character or `NULL` if the character is not found.

* **`ft_strrchr`**  
  Locates the last occurrence of the character `c` in the string `s`.  
  Returns a pointer to the matched character or `NULL` if the character is not found.

* **`ft_strncmp`**  
  Compares at most `n` bytes of the two strings `s1` and `s2`.  
  Returns an integer less than, equal to, or greater than zero if `s1` is found to be less than, to match, or be greater than `s2`.

* **`ft_memchr`**  
  Scans the initial `n` bytes of the memory area pointed to by `s` for the first instance of character `c`.  
  Returns a pointer to the matching byte or `NULL` if the character does not occur in the given memory area.

* **`ft_memcmp`**  
  Compares the first `n` bytes of memory areas `s1` and `s2`.  
  Returns an integer difference between the first two differing bytes.

* **`ft_strnstr`**  
  Locates the first occurrence of the null-terminated string `little` in the string `big`, where no more than `len` characters are searched.  
  Returns a pointer to the first character of the first occurrence, or `NULL` if not found.

* **`ft_atoi`**  
  Converts the initial portion of the string pointed to by `nptr` to an `int` representation.  
  Discards leading whitespace, handles optional signs (+/-), and parses digit sequences.

* **`ft_calloc`**  
  Allocates memory for an array of `nmemb` elements of `size` bytes each, initializing all bytes to zero.  
  Returns a pointer to the allocated memory, or `NULL` if allocation fails.

* **`ft_strdup`**  
  Allocates sufficient memory for a copy of the string `s1`, performs the copy, and returns a pointer to it.  
  Returns `NULL` if memory allocation fails.

---

#### Part 2 — Additional Functions (Mandatory)

* **`ft_substr`**  
  Allocates memory using `malloc` and returns a substring from string `s`.  
  The substring starts at index `start` and has a maximum length of `len`.

* **`ft_strjoin`**  
  Allocates memory using `malloc` and returns a new string resulting from concatenating `s1` and `s2`.  
  Returns `NULL` if memory allocation fails.

* **`ft_strtrim`**  
  Allocates memory and returns a copy of `s1` with characters specified in `set` removed from both the beginning and the end.  
  Returns `NULL` if memory allocation fails.

* **`ft_split`**  
  Allocates memory and returns an array of strings obtained by splitting `s` using character `c` as a delimiter.  
  The array of string pointers is terminated by a `NULL` pointer.

* **`ft_itoa`**  
  Allocates memory using `malloc` and returns a string representing the integer received as an argument.  
  Handles negative numbers correctly and returns `NULL` if allocation fails.

* **`ft_strmapi`**  
  Applies the function `f` to each character of string `s` to create a new string with `malloc`.  
  Passes the character index as the first argument to `f` and the character itself as the second.

* **`ft_striteri`**  
  Applies the function `f` to each character of the string `s`, passing its index as the first argument.  
  Each character is passed by address to allow modification in place.

* **`ft_putchar_fd`**  
  Outputs the character `c` to the given file descriptor `fd` using the `write` system call.  
  Produces no return value.

* **`ft_putstr_fd`**  
  Outputs the string `s` to the specified file descriptor `fd` using the `write` system call.  
  Produces no return value.

* **`ft_putendl_fd`**  
  Outputs the string `s` to the specified file descriptor `fd` followed by a newline character.  
  Produces no return value.

* **`ft_putnbr_fd`**  
  Outputs the integer `n` to the given file descriptor `fd`.  
  Handles negative numbers and full integer limits correctly.

---

#### Part 3 — Linked List Functions (Mandatory)

* **`ft_lstnew`**  
  Allocates memory using `malloc` and returns a new node structure (`t_list`).  
  Initializes `content` with the given parameter and sets `next` to `NULL`.

* **`ft_lstadd_front`**  
  Adds the node `new` at the beginning of the linked list `lst`.  
  Updates the pointer to the head of the list directly.

* **`ft_lstsize`**  
  Counts and returns the total number of nodes in the linked list starting at `lst`.  
  Traverses the list until the end (`NULL`) is reached.

* **`ft_lstlast`**  
  Traverses the list starting at `lst` and returns a pointer to the last node.  
  Returns `NULL` if the list is empty.

* **`ft_lstadd_back`**  
  Adds the node `new` at the end of the linked list `lst`.  
  Handles empty list cases where `*lst` is `NULL`.

* **`ft_lstdelone`**  
  Frees the memory of the given node's content using the function `del` and then frees the node itself.  
  Does not free or affect subsequent nodes in the list.

* **`ft_lstclear`**  
  Deletes and frees the given node and all successors using `del` and `free`.  
  Finally sets the pointer to the list to `NULL`.

* **`ft_lstiter`**  
  Iterates through the list `lst` and applies function `f` to the content of each node.  
  Does not alter the structure of the list.

* **`ft_lstmap`**  
  Iterates through `lst`, applying `f` to each node's content to create a new list.  
  Uses function `del` to clean up allocated memory if an allocation fails midway.

---

## Instructions

### Compilation & Build

The library is compiled using `make` with the mandatory compiler flags `-Wall -Wextra -Werror`.

```bash
# Compile libft.a library including all mandatory parts
make

# Clean object files (.o)
make clean

# Clean object files and libft.a
make fclean

# Recompile everything from scratch
make re
```

## Resources

### References & Documentation
* **C Standard Library Reference (`man 3`)** — Reference for standard libc functions.
* **42 Libft Project Subject Guidelines** — Official project guidelines, subject requirements, and constraints.


### AI Usage Declaration
In accordance with the 42 AI usage guidelines:

* **Tasks Assisted:** Troubleshooting errors, better understanding assignment instructions, research on expected behaviour for edge cases, providing pseudocode, writing test code for more advanced functions (<10 instances).
* **README Generation:** Used AI to generate this README.
* **No Direct Implementation:** All C codebase implementations (`ft_*.c`), Makefile rules, and core header declarations were developed independently without generating direct source code solutions via AI.
