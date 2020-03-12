#include <stdlib.h>
#include <stdio.h>


int main ()
{

int num;

FILE *fptr;

fptr = fopen ("file2.text", "w");


if (fptr == NULL)
{
printf("ERROR!");
exit(1);
}

printf("Enter some number: ");
scanf("%d", &num);

fprintf(fptr, "%d", num);
fclose(fptr);


return 0;
}
