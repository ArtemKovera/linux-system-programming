//a simple program for a signal handler
#include<stdio.h>
#include<signal.h>
#include<sys/wait.h>
#include<stdlib.h>

int n;
void signalHandler (int signum)
{
    printf("signal %d received - counter reset\n", signum);
    n = 0;
}

int main()
{
    signal (SIGINT, signalHandler);

    while(1)
    {
        printf("working %d\n", n++);
        sleep(1);
    }


    return 0;
}