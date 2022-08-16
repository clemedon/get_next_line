
# GNL - GET NEXT LINE - 42

***Whole code documented with docstrings.***

Get the next line of text available on a file descriptor.
Calling get_next_line in a loop will allow us to read the text available on the
file descriptor one line at a time until the end of it.

> "May it be a file, stdin, or even later a network connection, you will always
> need a way to read content line by line. It is time to start working on this
> function, which will be essential for your future projects." - [Subject](https://cdn.intra.42.fr/pdf/pdf/57350/en.subject.pdf)

## Index

**[Usage](#Usage)**<br>
**[Tester](#Tester)**<br>
**[Tools](#Tools)**<br>

## Usage

Add `get_next_line.h` to your project header to access the function.

To test the function run `make` from within the `test` directory and launch as
follows: `./get_next_line <path_to_file>`

For example: `./get_next_line main.c`

***Makefile rules***

- `make` -- compiles get_next_line.
- `make clean` -- deletes object files.
- `make fclean` -- deletes object files and get_next_line.
- `make re` -- fclean + make.

## Tester

**[Gnldiff](test/gnldiff.sh)** is a simple tester that check `get_next_line` output accuracy and create
a `diff.log` file if something went wrong.

Usage: `bash gnldiff.sh <file_path>`

Example:

    head -4242 /dev/urandom > file
    bash gnldiff.sh file

## Tools

- **[ft_mallocator](https://github.com/tmatis/ft_mallocator)**

- valgrind: `valgrind -q --leak-check=yes --show-leak-kinds=all`

- sanitizer: `-fsanitize=address`

> Add `-g` flag when compiling with `-fsanitize=address` to print errors line
> numbers instead of addresses in hexadecimal.
