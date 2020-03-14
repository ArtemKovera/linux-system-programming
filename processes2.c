#include <stdio.h>


int main ()
{
    int i;

    if (fork())
    {
	    for (i=0; i<100; i++) printf("**     PARENT %d\n", i);
    }
    else
    {
	    for (i=0; i<100; i++) printf("  **   CHILD  %d\n", i);
    }


    return 0;
}