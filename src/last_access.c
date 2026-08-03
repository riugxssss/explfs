#include <stdio.h>
#include <sys/stat.h>
#include "../include/last_access.h"

void show_last_access(struct stat fs){
    printf("Last access: %ld\n", fs.st_atime);
}

void show_last_modification(struct stat fs){
    printf("Last modification: %ld\n", fs.st_mtime);
}

void show_status_change(struct stat fs){
    printf("Last status change: %ld\n", fs.st_ctime);
}
