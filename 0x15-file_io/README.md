# 0x15. C - File I/O

Welcome to the "C - File I/O" project, where you'll dive into the fascinating world of file input and output operations in the C programming language. This project will equip you with the knowledge and skills to efficiently manage files, perform I/O operations, and handle file descriptors.

## Resources

### Read or watch:

#### File descriptors
**C Programming in Linux Tutorial #024 - open() read() write() Functions**
- A comprehensive tutorial exploring the usage of `open()`, `read()`, and `write()` functions in Linux programming.
- Man Pages:
  - `man 2 open`
  - `man 2 close`
  - `man 2 read`
  - `man 2 write`
  - `man 3 dprintf`

## General

### Look for the right source of information online
Learning about file I/O requires reliable sources. Look for reputable tutorials, official documentation, and community forums to deepen your understanding.

### How to create, open, close, read and write files
Files are integral to software systems. Learn how to create, open, close, read, and write files in C, and gain hands-on experience in managing file data.

### What are file descriptors
File descriptors are unique identifiers for open files. They serve as a bridge between your program and the operating system's I/O functions. Understanding file descriptors is crucial for successful file manipulation.

### What are the 3 standard file descriptors, what are their purpose and what are their POSIX names
- **STDIN (0):** Standard input. Data is read from this descriptor, typically from the keyboard or input stream.
- **STDOUT (1):** Standard output. Data is written to this descriptor, often displayed in the terminal or output stream.
- **STDERR (2):** Standard error. Used for error messages and diagnostics.

### How to use the I/O system calls open, close, read and write
Mastering system calls is key to efficient file I/O. Learn how to use `open()`, `close()`, `read()`, and `write()` to manipulate files, control data flow, and optimize performance.

### What are and how to use the flags O_RDONLY, O_WRONLY, O_RDWR
File access modes are defined by flags like `O_RDONLY`, `O_WRONLY`, and `O_RDWR` when opening files with the `open()` function. Use these flags to tailor permissions to your needs.

### What are file permissions, and how to set them when creating a file with the open system call
File permissions dictate who can read, write, or execute a file. Explore how to set file permissions using `open()`, ensuring proper data protection and access control.

### What is a system call
A system call is a mechanism for programs to request services from the operating system's kernel. Understand the powerful role system calls play in accessing kernel-level functionalities.

### What is the difference between a function and a system call
Functions and system calls both execute code, but system calls transition from user mode to kernel mode for privileged operations. Gain insights into the distinctions between these two essential programming concepts.

## How to Compile

To compile your C programs for the "C - File I/O" project, follow these steps:

1. **Open a Terminal:** Launch a terminal on your system. You can usually find the terminal application in your system's applications menu.

2. **Navigate to Your Project Directory:** Use the `cd` command to navigate to the directory where your C source code files are located. For example:
   cd /path/to/your/project/directory

3. **Compile Using gcc:**  Use the gcc (GNU Compiler Collection) command to compile your C source code files. The basic syntax is as follows:
	**gcc -o output_filename input_filename.c**


## Happy Coding :)
