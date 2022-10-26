/*Program to implement linear search*/
#include <stdio.h>
main()
{
 int a[20],n,key,i;
 printf ("input the array size:");
 scanf ("%d",&n);
 printf ("enter the array elements:");
 for (i=0;i<=(n-1);i++)
 scanf ("%d",&a[i]);
 printf("\n input key element:");
 scanf ("%d",&key);
 for(i=0;i<=(n-1);i++)
 {
    if (a[i]==key)
 {
    printf("\nthe key element %d is found at %d position-sucessful search",key,i+1);
 break;
}
}
if (i==n)
printf("\n the key element %d is not present in the list-unsuccessful search",key);
}
