#include <stdio.h>

int main () {
		int A [9] = {11,23,-8,49,69,-53,0,07,-02};
		int i,x,y;
		i=0;
		printf("the values on array :");
		while (i<9)
		{
		printf(" %d",A [i]);
		i=i+1;
		
	}	
	
	printf("\nenter the number to search");
	scanf("%d",&x);
	i=0;
	y=-1;
	while(i<9)
	{
	if (x==A[i])
	{
	y=i;
	}
	i=i+1;
	}
	if(y==-1)
	{
	
	printf("the value does not found");
	}
else
printf("the value found at location :%d",y);
	
return 0;	
}
