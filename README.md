# get_next_line

get_next_line is a project developed for 42 Heilbroon School.

## Keywords
C programming - read() - file descriptor - buffer - static variable

## Subject
In this project I had to create a function which `read()` from a file everytime is called, line by line. For more info about the requirements, take a look at the [subject](en.subject.pdf) contained in this repo.

## Brief explanation
The project covers the following topics:

### 1. Static variable

### 2. Collecting data

### 3. Use of the graphical library

### 4. Leaks free
Like in any other project of 42, the memory allocated by `malloc()` has to be properly sfreed. No leaks are tolerated. In this project I checked the leaks using [valgrind](https://valgrind.org/) and `system("leaks <program-name>")`

## Bonus
In the bonus part of the project the goal is use `get_next_line` function to read more than one file descriptor simultaneously, keeping trace of the next line of each file.

---

## Try it out
1. Clone the repository:
```
git clone git@github.com:NicoCastelnuovo/get_next_line.git get_next_line
```
2. Navigate to the `get_next_line` directory and `make` the archive, or `make bonus` for more funcionalities:
```
cd get_next_line
make
```
3. To use the function in inside your .c file, you have to include the header on the top of it:
```
#include "get_next_line.h"
```
4. Compile your executable:
```
cc <your_main.c> ./<gnl_path>/libgnl.a -I ./<gnl_path>/get_next_line.h -o <program_name>
```
> **Note:** if you need to `open()` the file and `read()`, remember to `# include <fcntl.h>` header inside your project!

5. Enjoy!

> **Note:** get_next_line is part of `mylib`, a personal collection of libraries and functions used in the 42 Heilbronn projects. [Check it out!](https://github.com/NicoCastelnuovo/mylib)
