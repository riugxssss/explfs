#ifndef FI_H
#define FI_H

#include <sys/stat.h>

void print_file_info(struct stat fi, const char *pathname);
#endif
