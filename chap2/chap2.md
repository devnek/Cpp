# Header Files

Header files in C are files with a `.h` extension that contain function declarations, macro definitions, type definitions, and other information that you want to share across multiple source files. They are used to promote code modularity and reusability by separating declarations from their implementations.

## Why Use Header Files?

1. **Reusability:** You can reuse the declarations in multiple programs without rewriting them.
2. **Modularity:** Code becomes more organized by separating interface (declarations) from implementation (definitions).
3. **Readability:** Header files make your codebase easier to understand by summarizing what a program provides.
4. **Maintenance:** If you need to update a function's interface, you only have to modify the header file.

## How Header Files Work

### Inclusion in Source Files

A header file is included in a source file (`.c`) using the `#include` directive. For example:

```c
#include "my_header.h"
```

This literally copies the contents of the header file into the source file at compile time.

### Guards Against Multiple Inclusions

Use **include guards** or `#pragma once` to prevent a header file from being included multiple times in the same program, which would lead to errors. For example:

```c
#ifndef HEADER_FILE_NAME_H
#define HEADER_FILE_NAME_H

// Declarations go here

#endif // HEADER_FILE_NAME_H
```

### Separation of Declaration and Definition

- **Declaration:** A function or variable is declared in the header file. For example:

```c
int add(int a, int b); // Declaration
```

- **Definition:** The actual implementation of the function is written in a source file. For example:

```c
int add(int a, int b) {
	return a + b;
}
```

## Types of Header Files

### 1. Standard Header Files

These are built into the C Standard Library and include:
- **`<stdio.h>`** for input/output functions.
- **`<stdlib.h>`** for general utilities like memory allocation.
- **`<string.h>`** for string manipulation functions.
- **`<math.h>`** for mathematical operations.

Example:

```c
#include <stdio.h>
printf("Hello, World!\n");
```

### 2. Custom Header Files

These are user-defined and created for modular code. You can define your own functions, macros, or constants and include them in your projects.

### Example of How Header Files Work

Here's a simple example to understand the concept:

**Custom Header File: `my_header.h`**

```c
#ifndef MY_HEADER_H
#define MY_HEADER_H

// Function declaration
int square(int x);

#endif // MY_HEADER_H
```

**Implementation File: `my_header.c`**

```c
#include "my_header.h"

int square(int x) {
	return x * x;
}
```

**Main File: `main.c`**

```c
#include <stdio.h>
#include "my_header.h"

int main() {
	int number = 5;
	printf("Square of %d is %d\n", number, square(number));
	return 0;
}
```

**Compilation and Execution:**

```bash
gcc main.c my_header.c -o program
```

## Best Practices for Header Files

1. **Use Include Guards or `#pragma once`** — Prevent multiple inclusions to avoid compiler errors.
2. **Keep Headers Lightweight** — Avoid putting large implementations in the header file—use them only for declarations.
3. **Group Related Declarations** — Group functions, macros, and type definitions logically for better organization.
4. **Document the Header File** — Provide comments to explain the purpose of each declaration for clarity.

Header files are a cornerstone of clean and maintainable C programming. They are especially useful in large projects to manage code complexity and allow teamwork by separating interfaces from implementations.

---

# Exercise: Using Custom Header Files

This exercise will guide you in creating and using a custom header file in C.

## Task

1. Create a header file `math_operations.h` that declares two functions:
   - A function to add two integers.
   - A function to multiply two integers.
2. Implement the functions in `math_operations.c`.
3. Write a `main.c` program that uses these functions to perform operations and print the results.

## Solution

### Header File: `math_operations.h`

```c
// chap2/code/math_operations.h
#ifndef MATH_OPERATIONS_H
#define MATH_OPERATIONS_H

int add(int a, int b);
int multiply(int a, int b);

#endif
```

### Source File: `math_operations.c`

```c
// chap2/code/math_operations.c
#include "math_operations.h"

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}
```

### Main Program: `main.c`

```c
// chap2/code/main.c
#include <stdio.h>
#include "math_operations.h"

int main() {
    int a, b;
    printf("Enter the first number: ");
    scanf("%d", &a);
    printf("Enter the second number: ");
    scanf("%d", &b);
    printf("Sum: %d\n", add(a, b));
    printf("Product: %d\n", multiply(a, b));
    return 0;
}
```

## Compilation and Execution

```bash
cd chap2/code
gcc main.c math_operations.c -o program
./program
```

## Expected Output

```
Enter the first number: 5
Enter the second number: 10
Sum: 15
Product: 50
```

---

# Best Practices for Header Files

- Use include guards or `#pragma once` to prevent multiple inclusions.
- Keep header files lightweight by avoiding large implementations.
- Group related declarations logically.
- Add comments to improve readability and maintainability.
