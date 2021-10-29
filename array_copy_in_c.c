#include <stdio.h>
#define ARRAY_SIZE 10

int main () {
	int copied [9];
	int i,a,x;
	

    int numbers[ARRAY_SIZE];

    for (i = 0; i < ARRAY_SIZE; i++)
    {
		printf("Enter the Number : %d  : ", (i+1));
        scanf("%d", &numbers[i]);
    }

i=0;
while(i<10)
{
a=numbers[i];
copied[i]=a;
i=i+1;
}
i=0;
printf(" \nCopied array ");
while(i<10)
{printf("%d ",copied[i]);
i=i+1; }


	

return 0;	
}
