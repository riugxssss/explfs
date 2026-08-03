#include "../include/get_pathnamesymlink.h"

void real_symlnk_path(const char *sympath){

    char buf[512] = {0};

    ssize_t ret = readlink(sympath, buf, sizeof(buf) - 1);

    if (ret == -1){
        fprintf(stderr, "explfs: errno: %d error: %s\n", errno, strerror(errno));
        return;
    }

    buf[ret] = '\0';

    printf("Path link: %s\n", buf);

}
