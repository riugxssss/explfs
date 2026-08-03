
#include <stdio.h>
#include <pwd.h>
#include <grp.h>
#include "owner.h"

void print_owner(uid_t user_id,gid_t group_id){
     struct passwd *pw= getpwuid(user_id);
     struct group  *gr=  getgrgid(group_id);

     printf("Owner : %s (%u)\n", pw ? pw->pw_name: "unknown", user_id);
     printf("Group : %s (%u)\n", gr ? gr->gr_name: "unknown", group_id);
}
