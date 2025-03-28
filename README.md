# ft_printf

## Overview

**ft_printf** is a custom implementation of the standard C `printf` function. It replicates its behavior while adhering to the constraints and requirements set by the 42 curriculum. The project focuses on handling formatted output with various specifiers and ensuring efficient memory management.

## Features

- Supports the following format specifiers:
  - `%c` (Character)
  - `%s` (String)
  - `%p` (Pointer)
  - `%d` / `%i` (Signed integer)
  - `%u` (Unsigned integer)
  - `%x` / `%X` (Hexadecimal representation, lowercase/uppercase)
  - `%%` (Percent sign)
- Uses variadic arguments (`va_list`)
- Outputs to file descriptor `1` (standard output)

## Installation

To use `ft_printf` in your project, compile it as a static library:

```sh
make
```

This will generate `libftprintf.a`, which you can link to your project.

## Usage

Include the header and link the library in your C project:

```c
#include "ft_printf.h"

int main()
{
    ft_printf("Hello, %s! The number is %d.\n", "world", 42);
    return 0;
}
```

Compile and link with:

```sh
gcc main.c -L. -lftprintf -o my_program
```

## Project Structure

- `src/` - Source files implementing `ft_printf` and helper functions
- `inc/` - Header files
- `obj/` - Compiled object files
- `Makefile` - Build automation script

## Compliance

This project follows the 42 school’s coding style (`norminette`) and does not contain any prohibited content, such as evaluation subjects or full solutions. It serves as a demonstration of programming skills and does not violate the pedagogical principles of 42.

## License

This project is developed as part of the 42 curriculum and is intended for learning purposes. Redistribution of source code should comply with 42’s guidelines.

