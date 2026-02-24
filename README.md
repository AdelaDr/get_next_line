*This project has been created as part of the 42 curriculum by adrahoto.*

[![C](https://img.shields.io/badge/language-C-555?style=flat&logo=c)](https://en.wikipedia.org/wiki/C_(programming_language))
[![42 Project](https://img.shields.io/badge/42-Libft-blue)](https://www.42.fr)

# Table of Contents
- [Description](#description)
- [Instructions](#instructions)
- [Resources](#resources)
- [Feature list](#feature-list)
- [Usage Example](#usage-example)
- [Technical Choices](#technical-choices)

# Description
This project implements the `get_next_line` function in C, designed to read files or standard input one line at a time. The goal is to understand low-level file I/O, memory management, and static variables by creating a function that efficiently handles arbitrary-length lines using only allowed system calls and C standard features.

The custom `get_next_line` function reads from a file descriptor, stores leftover data between calls, and returns each line including the newline character (`\n`) when present. It emphasizes:

- Managing static variables for persistent buffer data

- Reading data efficiently using a buffer

- Dynamically allocating memory for each line

- Writing clean, modular, and reusable C code

This implementation serves as both a practical file-reading utility and a learning exercise in low-level I/O, memory handling, and buffer management.

# Instructions
## Automatic Compilation
Clone and compile:
```bash
git clone https://github.com/AdelaDr/get_next_line.git
cd get_next_line
make
```

Generates `get_next_line.a` automatically.

## Usage in Projects

Include the header and link your files:

```bash
#include "get_next_line.h"
```

```bash
cc -Wall -Wextra -Werror main.c get_next_line.c get_next_line_utils.c -o my_program
```

# Resources

- [C Standard Library Docs](https://man7.org/linux/man-pages/man3/)

- [W3Schools](https://www.w3schools.com)

- Manual pages for read, malloc, free

- AI assistance: used for code structuring, debugging hints, and logic explanation

# Feature List

Reimplementation of line-by-line file reading as `get_next_line`

- Read a file descriptor line by line

- Static buffer management to preserve leftover data between calls

- Dynamic memory allocation for each line returned

- Support for variable buffer size via `BUFFER_SIZE` macro

- Handles multiple file descriptors (if bonus implemented)

- Robust memory handling with `malloc` and `free`

- Efficient reading using the `read` system call without loading entire files into memory

- Modular implementation with helper functions for string joining, searching for newlines, and buffer updates

# Usage Example

```bash
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

# Technical Choices

- **Static Variables**
Used to store leftover data between function calls, allowing `get_next_line` to continue reading where it left off without losing unprocessed data.

- **Buffered Reading**
Data is read into a temporary buffer of size `BUFFER_SIZE`, optimizing system calls while supporting arbitrary line lengths.

- **Dynamic Memory Management**
Each line is allocated with `malloc` and freed by the user after use, ensuring memory safety and flexibility.

- **String Utility Functions**
Custom helper functions handle string concatenation, searching for newlines, and updating buffers, keeping the main function modular and readable.

- **Low-Level File I/O**
The `read` system call is used exclusively to comply with project restrictions and reinforce understanding of Unix file handling.

- **Modular Design**
Each subtask (buffer management, newline detection, line extraction) is separated into dedicated functions for clarity and maintainability.

- **Error Handling**
The function gracefully handles end-of-file and read errors, returning `NULL` when appropriate and avoiding undefined behavior.