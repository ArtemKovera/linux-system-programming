#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <errno.h>
#include <stdlib.h>

int main (int argc, char * argv[])
{
    struct stat sb; 

    //array of file types, indexed by the top four bits of st_mode
    char *filetype[] = {"unknown", "FIFO", "character device", "unknown",
    "directory", "unknown", "block device", "unknown", "file",
    "unknown", "symlink", "unknown", "socket"};

    if(argc != 2)
    {
        fprintf(stderr, "usage: listfile filename\n");
        exit(1);
    }

    if (stat(argv[1], &sb) < 0)
    {
        perror(argv[1]);
        exit(2);
    }

    printf("file type: %s\n", filetype[(sb.st_mode >> 12) & 017]);
    printf("permitions: %c%c%c%c%c%c%c%c%c\n", 
    (sb.st_mode & S_IRUSR) ? 'r' : '-',
    (sb.st_mode & S_IWUSR) ? 'w' : '-',
    (sb.st_mode & S_IXUSR) ? 'x' : '-',
    (sb.st_mode & S_IRGRP) ? 'r' : '-',
    (sb.st_mode & S_IWGRP) ? 'w' : '-',
    (sb.st_mode & S_IXGRP) ? 'x' : '-',
    (sb.st_mode & S_IROTH) ? 'r' : '-',
    (sb.st_mode & S_IWOTH) ? 'w' : '-',
    (sb.st_mode & S_IXOTH) ? 'x' : '-'
    );

    

    return 0;
}