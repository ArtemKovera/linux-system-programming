#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>


int main ()
{
    int fd;
    fd = open("foo2", O_WRONLY | O_CREAT, 0644);
    if(fd < 0)
    {
        printf("errno number %d\n", errno);
        perror("foo");
        exit(1);
    }
    else
    {
        write(fd, "hello world again", 17);
        close(fd);        
    }
    


    return 0;
}