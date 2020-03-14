//a simple program to create files with different permissions

#include <sys/stat.h>


int main ()
{
    umask(0);
    creat("file1", 0755);

    umask(077);
    creat("file2", 0755);

    creat("file3", 0);
    chmod("file3", S_IRUSR | S_IWUSR);

    system("ls -l file?");

    return 0;
}

