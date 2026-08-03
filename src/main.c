
#include <stdio.h>
#include <sys/stat.h>
#include "fileinfo.h"
int main(int argc,char **argv){
    
    if(argc!=2){
        fprintf(stderr, "explfs: %s <file>\n",argv[0]);
        return 1;
    }
    struct stat fi;
    if(stat(argv[1],&fi)==-1){
        fprintf(stderr, "explfs: <stat> in line: %d\n", __LINE__);
        return 1;
    }
    print_file_info(fi, argv[1]);
    return 0;
}
