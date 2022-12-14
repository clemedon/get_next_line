<h1 align="center">
	GNL - GET_NEXT_LINE 42
</h1>

<h3 align="center">
	<a href="#Summary">Summary</a>
	<span> · </span>
	<a href="#Usage">Usage</a>
	<span> · </span>
	<a href="#Tester">Tester</a>
	<span> · </span>
	<a href="#Tools">Tools</a>
</h3>

## Summary

Get the next line of text available on a file descriptor.
Calling get_next_line in a loop will allow us to read the text available on the
file descriptor one line at a time until the end of it.  

> *"May it be a file, stdin, or even later a network connection, you will always
> need a way to read content line by line. It is time to start working on this
> function, which will be essential for your future projects."* - [Subject](https://cdn.intra.42.fr/pdf/pdf/57350/en.subject.pdf)

External functions: `read`, `malloc`, `free`

Code written in accordance with **42 C** coding style,  **ANSI C89** compliant and entirely **documented with docstrings**.

## Usage

Add `get_next_line.h` to your project header to access the function.

To test the function run `make` from within the `test` directory and launch as
follows: `./get_next_line <path_to_file>`

For example: `./get_next_line main.c`

## Tester

**First of all** `cd test && make`.

- **[Gnltester](test/gnltester.sh)** check if the number of characters returned by
  `get_next_line` call on multiple pre defined input files with a set of
  different BUFFER_SIZE is correct.  Uses valgrind.

Usage: `make test` or `bash gnltester.sh`

- **[Gnldiff](test/gnldiff.sh)** is a simple tester that check `get_next_line` output accuracy and create
a `diff.log` file if something went wrong.

Usage: `bash gnldiff.sh <file_path>`

Example:

    cat Makefile > file; bash gnldiff.sh file

    cat ../*.[ch] > file; bash gnldiff.sh file

**Make sure to** use a `BUFFER_SIZE` of 1 if your `<file>` parameter contains
multi byte characters like those from binary file or `/dev/urandom` like:

    cat /bin/cat > file; bash gnldiff.sh file

    head -4242 /dev/urandom > file; bash gnldiff.sh file

- **[gnlTester](https://github.com/Tripouille/gnlTester)**

## Tools

- **[ft_mallocator](https://github.com/tmatis/ft_mallocator)**

*Check with different arguments (ft_mallocator/config.sh:`ARGS`) and buffer size (get_next_line.h:`BUFFER_SIZE`).*

- **valgrind**: `valgrind -q --leak-check=yes --show-leak-kinds=all`

- **sanitizer**: `-fsanitize=address`

*Add `-g` flag when compiling with `-fsanitize=address` to print errors line numbers instead of addresses in hexadecimal.*
