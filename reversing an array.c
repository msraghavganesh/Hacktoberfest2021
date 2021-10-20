#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int i,n;
	printf("enter no of elements needed\n");
	scanf("%d",&n);
	
	int a[n];
	int riv_a[n];
		
	printf("enter elements\n");
	for (i=0;i<n;i++)
	{
		scanf("%d\n",&a[i]);
	}
	
	for(i=0;i<n/2;i++)
	{
		riv_a[i]=a[n-1-i];
	
	}
	printf("reversed array\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",riv_a[i]);
	}

	return 0;
}
