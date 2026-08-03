# explfs

`explfs` is a small C project developed to practice working with the Linux file system APIs, in particular the `stat`, `lstat`, and `readlink` system interfaces.

The program inspects a file or directory and displays information about it, including its type, owner, and permissions.

## Features

* Detects the file type using the information stored in `struct stat`.
* Prints Unix file permissions for the owner, group, and others.
* Displays the file owner (UID/GID).
* Correctly distinguishes symbolic links from regular files by using `lstat()` instead of `stat()`.
* Reads the destination of symbolic links using `readlink()`.

## Concepts Practiced

This project was created as an exercise to better understand several Linux system programming concepts:

* Using `stat()` to retrieve file metadata.
* Understanding the `st_mode` field and file type macros (`S_ISREG`, `S_ISDIR`, `S_ISLNK`, etc.).
* Reading and interpreting Unix permission bits.
* Understanding the difference between `stat()` and `lstat()`.
* Working with symbolic links using `readlink()`.
* Organizing a C project into multiple source and header files.
* Building the project with a Makefile.

## Building

Compile the project with:

```bash
make
```

Clean the build files with:

```bash
make clean
```

## Technologies

* C11
* GCC
* POSIX/Linux System Calls
* Make

## Purpose

The goal of this project was not to recreate the full functionality of `ls`, but to gain practical experience with Linux file metadata, permissions, and symbolic links while writing clean, modular C code.
