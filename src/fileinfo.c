#include <stdio.h>
#include "../include/fileinfo.h"
#include "../include/filetype.h"
#include "../include/owner.h"
#include "../include/permissions.h"
#include "../include/get_pathnamesymlink.h"
#include "../include/last_access.h"
#include <sys/stat.h>

void print_file_info(struct stat fi, const char *pathname){

    printf("Type : ");

    lstat(pathname, &fi);

    if (S_ISLNK(fi.st_mode)){
        printf("Symbolic Link\n");
        real_symlnk_path(pathname);
    }else {
        file_type(fi);
    }

    printf("Inode: %lu\n", (unsigned long) fi.st_ino);

    printf("Size : %lld bytes\n", (long long) fi.st_size);

    printf("Links: %lu\n", (unsigned long) fi.st_nlink); 

    printf("Info access\n");
    show_last_access(fi);
    show_last_modification(fi);
    show_status_change(fi);

    print_owner(fi.st_uid, fi.st_gid);
    show_permissions(fi.st_mode);
}
