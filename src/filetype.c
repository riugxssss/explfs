#include <stdio.h>
#include "filetype.h"

int file_type(struct stat fs){

    switch (fs.st_mode & S_IFMT) {

    case S_IFREG:
        printf("Regular file\n");
        break;

    case S_IFDIR:
        printf("Directory\n");
        break;
    case S_IFCHR:
        printf("Character device\n");
        break;

    case S_IFBLK:
        printf("Block device\n");
        break;

    case S_IFIFO:
        printf("FIFO\n");
        break;

    case S_IFSOCK:
        printf("Socket\n");
        break;

    default:
        printf("Unknown file type\n");
        break;
    }

    return 0;
 }
