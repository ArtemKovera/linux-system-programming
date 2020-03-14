//using pipes
//this program is equivalent to "ls | sort -r" command line

#include <unistd.h>

int main ()
{
    int p[2];

    pipe(p); //create the pipe

    if(fork() == 0)
    {
        //child: connect stdout to pipe
        dup2(p[1], 1);
        close(p[0]);
        execlp("ls", "ls", (char *)0);
    }

    //parent: connect stdin to pipe
    dup2(p[0], 0);
    close(p[1]);
    execlp("sort", "sort", "-r", (char *) 0);


    return 0;
}