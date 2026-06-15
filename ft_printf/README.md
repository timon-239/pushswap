*This project has been created as part of the 42 curriculum by eboualla.*

# ft_printf

## Description

A custom implementation of the standard C "printf" function, that supports formatted output through various conversion specifiers:

%c Prints a single character  
%s Prints a string (as defined by the common C convention)  
%p The void * pointer argument has to be printed in hexadecimal format  
%d Prints a decimal (base 10) number  
%i Prints an integer in base 10  
%u Prints an unsigned decimal (base 10) number  
%x Prints a number in hexadecimal (base 16) lowercase format  
%X Prints a number in hexadecimal (base 16) uppercase format  
%% Prints a percent sign  

The project focuses on deepening understanding of variadic funtions, parsing and low-level output handling in C.

### Undefined Behavior

In the case of undefined behavior, the program behaves like the original `printf`, as in “abc%” or “ab%y”, and returns the entered string without the %-sign at the end or exactly as entered.

## Instructions

### Algorithm & Data Structure

The algorithm works by scanning the format string one character at a time.  
If a conversion specifier is found after %, the corresponding handler function is called to print the argument.

The implementation relies on va_list for handling variadic arguments and uses separate helper functions for each data type to keep the code organized and maintainable.

### Compilation

To compile the library, run:

```bash

make        # builds the library
make clean  # removes object files
make fclean # removes object files and the library
make re     # fully rebuilds the project

```
---

## Resources
printf man page  
stdarg man page  
https://www.geeksforgeeks.org/c/variadic-functions-in-c/  
https://en.wikipedia.org/wiki/Printf  
https://www.hackerearth.com/practice/notes/void-pointer-in-c/#:~:text=A%20void%20pointer%20is%20a,be%20typcasted%20to%20any%20type.&text=Note%20that%20the%20above%20program,of%20malloc%20to%20(int%20*).

### AI Usage

ChatGPT was used as a learning assistant during the development of this project.

All code was written and tested manually. AI was used only for explanations, debugging help, and conceptual understanding.
