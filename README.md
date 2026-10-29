# explfs

A small Linux utility written in C that inspects files and directories using the POSIX filesystem metadata APIs. The project focuses on `stat()`, `lstat()`, `readlink()`, permission bits, owner information, and file-type detection.

This project is intentionally narrow and educational: it is not a replacement for `ls` or `stat`, but it demonstrates practical low-level Linux file-system programming.

## Overview

`explfs` accepts a path as input and prints a structured summary of file metadata, including:

- file type
- inode number
- size
- link count
- timestamps
- owner and group information
- permission bits
- symlink target when applicable

The implementation is deliberately modular, which makes it easier to follow the logic and understand how Linux exposes metadata through `struct stat`.

## Features

The project currently implements the following verified behavior:

- file type detection using `struct stat`
- symlink detection using `lstat()`
- symbolic link target resolution with `readlink()`
- owner and group reporting via UID/GID
- permission display for owner/group/other access
- special bit reporting for setuid, setgid, and sticky
- access/modification/status-change timestamps
- structured metadata output for a single path

## Technical implementation

The project is built on standard Linux file APIs:

- `stat()` and `lstat()` read file attributes
- `S_ISREG`, `S_ISDIR`, `S_ISLNK`, and related macros classify file types
- `struct stat` contains inode, size, mode, times, and ownership fields
- `readlink()` resolves symlink targets
- `mode_t` is used to inspect permission flags and special mode bits

The code is split into focused modules:

- `src/main.c` — command-line entry point
- `src/fileinfo.c` — prints the metadata summary
- `src/filetype.c` — interprets file type information
- `src/permissions.c` — prints permission bits
- `src/owner.c` — prints uid/gid ownership
- `src/last_access.c` — handles timestamp output
- `src/get_pathnamesymlnk.c` — resolves symlink paths
- `include/` — header declarations

## Repository structure

- `src/` — implementation files
- `include/` — interface and support declarations
- `Makefile` — build automation
- `README.md` — project documentation

## Prerequisites

- Linux or a Unix-like environment
- GCC or Clang
- Make
- standard POSIX C library

## Build

From the repository root:

```bash
make
```

This produces an executable called `explfs` in the project root.

To remove generated build artifacts:

```bash
make clean
```

## Usage

Run the program with a target file or directory:

```bash
./explfs /path/to/file
```

Example:

```bash
./explfs /etc/passwd
```

Typical output includes:

```text
Type : Regular file
Inode: 220234
Size : 12345 bytes
Links: 1
...
Permissions
...
```

## Known limitations

- this is a learning-focused project rather than a production-ready file utility
- it does not emulate the full range of GNU `ls` or `stat` functionality
- it is Linux-specific and depends on POSIX/Linux metadata semantics
- there are no automated tests in the repository
- error handling is intentionally minimal

## Future improvements

Possible next steps:

- richer CLI flags such as `-l`, `-a`, and `-h`
- better formatting and output modes
- multi-path support
- tests for metadata parsing and edge cases
- more complete handling of filesystem metadata

## License

This repository includes a license file. Verify the repository metadata before relying on it as a legal statement.

## Related concepts

- Linux filesystem APIs
- POSIX metadata handling
- inode semantics
- permissions and ownership
- systems programming
