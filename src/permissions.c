#include <stdio.h>
#include "permissions.h"
#include <sys/stat.h>

static void print_permission(mode_t mode, mode_t bit, const char *name)
{
    printf("    %-8s : %s\n", name, (mode & bit) ? "yes" : "no");
}

void show_permissions(mode_t mode)
{
    printf("\nPermissions\n");

    printf("\nOwner\n");
    print_permission(mode, S_IRUSR, "read");
    print_permission(mode, S_IWUSR, "write");
    print_permission(mode, S_IXUSR, "execute");

    printf("\nGroup\n");
    print_permission(mode, S_IRGRP, "read");
    print_permission(mode, S_IWGRP, "write");
    print_permission(mode, S_IXGRP, "execute");

    printf("\nOthers\n");
    print_permission(mode, S_IROTH, "read");
    print_permission(mode, S_IWOTH, "write");
    print_permission(mode, S_IXOTH, "execute");

    printf("\nSpecial\n");
    print_permission(mode, S_ISUID, "setuid");
    print_permission(mode, S_ISGID, "setgid");
    print_permission(mode, S_ISVTX, "sticky");
}
