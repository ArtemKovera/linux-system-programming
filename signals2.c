// Demonstration of using SIGALRM to force a timeout

#include <stdio.h>
#include <setjmp.h>
#include <signal.h>
#include <errno.h>

void timeoutHandler(int unused)
{
  // Nothing to do
}

int tGetNum(int timeout)
{
  int n;
  char line[100];
  struct sigaction Action;

  Action.sa_handler = timeoutHandler;
  sigemptyset(&Action.sa_mask);
  Action.sa_flags = 0; 
  sigaction(SIGALRM, &Action, NULL);

  alarm(timeout);
  n = read(0, line, 100);
  alarm(0);  // Cancel alarm
  if (n == -1 && errno == EINTR) return -1;
  n = atoi(line);
  return n;
}

int main()
{
    int num;

    while(1) 
    {
        printf("enter a number: "); fflush(stdout);
        if ((num = tGetNum(5)) == -1) printf("timed out!\n");
        else printf("You entered %d\n", num);
    }

  return 0;
}