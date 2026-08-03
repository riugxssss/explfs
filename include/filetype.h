#ifndef FILETYPE_H
#define FILETYPE_H
#include <sys/stat.h>
#include <sys/types.h>

int file_type(struct stat fs);
#endif
