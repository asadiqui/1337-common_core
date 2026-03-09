# get_next_line (GNL)

## 🗣️ About The Project
The goal of this project is to create a function that returns a line read from a file descriptor.
It introduces the concept of static variables in C and proper buffer manipulation. It must work perfectly, without memory leaks, regardless of the size of `BUFFER_SIZE`.

## ⚙️ How it Works
- Repeatedly calls `read()` on the given file descriptor (`fd`) until a newline (`\n`) or End-Of-File (EOF) is encountered.
- Accumulates the read chunks dynamically handling any `BUFFER_SIZE`.
- Retains any leftover characters strictly after the newline in a `static char *` variable for the next function call.

## ✨ Bonus Features
- Capability to manage multiple file descriptors simultaneously utilizing a single static array of pointers.

## 🛠️ Usage
Include `get_next_line.h` and compile utilizing `get_next_line.c` and `get_next_line_utils.c`.
```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void) {
    int fd = open("test.txt", O_RDONLY);
    char *line;
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```
