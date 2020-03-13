#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>

int main ()
{
    DIR *d;
    struct dirent *info; //directory entry
    struct stat sb; // stat buffer
    long total = 0; //total of file size

    d = opendir(".");

    while ((info = readdir(d)) != NULL)
    {
        stat(info->d_name, &sb);
        total += sb.st_size;
    }

    closedir(d);
    printf("total size = %ld\n", total);

    return 0;
}