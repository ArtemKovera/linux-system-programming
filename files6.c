#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <errno.h>
#include <stdlib.h>

int main ()
{
    struct stat sb; //the stat buffer

    if(stat("foo", &sb) == -1)
    {
        printf("errno number %d\n", errno);
        perror("foo");
        exit(1);
    }
    else
    {
        printf("last accessed: %s", ctime(&sb.st_atime));
        printf("last modified: %s", ctime(&sb.st_mtime));
        printf("last change: %s", ctime(&sb.st_ctime));
    }



    return 0;
}