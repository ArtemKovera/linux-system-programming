#include <stdio.h>

int main ()
{
    if(fork()) printf("PARENT process\n");
    else printf("CHILD process\n");
  
    return 0;
}