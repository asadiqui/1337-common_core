# ft_printf

## 🗣️ About The Project
A project aiming to recreate a simplified version of the standard C library function `printf`. 
It introduces the use of variadic arguments (`va_list`) and structural program design for handling different formatting options securely and efficiently.

## 🔠 Supported Conversions
- `%c`: Prints a single character.
- `%s`: Prints a string (as defined by the common C convention).
- `%p`: The void * pointer argument is printed in hexadecimal format.
- `%d`: Prints a decimal (base 10) number.
- `%i`: Prints an integer in base 10.
- `%u`: Prints an unsigned decimal (base 10) number.
- `%x`: Prints a number in hexadecimal (base 16) lowercase format.
- `%X`: Prints a number in hexadecimal (base 16) uppercase format.
- `%%`: Prints a percent sign.

## 🛠️ Usage
Compile simply by running `make` to produce `libftprintf.a`.
Include `ft_printf.h` in your source and compile against the static library.
