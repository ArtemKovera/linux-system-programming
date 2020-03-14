//a little program to show value of specific environment variables

#include<stdio.h>
#include<stdlib.h>

int main (int argc, char * argv[])
{
   char *value;

   for (int i = 1; i < argc; i++)
   {
       if((value = getenv(argv[i])) != NULL)
       {
           printf("%s: %s\n", argv[i], value);
       }
       else
       {
           printf("%s: not in environment\n", argv[i]);
       }
       
   }


    return 0;
}