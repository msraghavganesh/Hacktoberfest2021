#include <stdio.h>
int main()
{
    int n,i,d,p;
    printf("Enter the length of array : ");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        printf("Enter the value for  element %d : ",i+1);
        scanf("%d",&a[i]);
    }

    printf("Enter the position you want to update : ");
    scanf("%d",&p);
    printf("Enter value for position %d : ",p);
    scanf("%d",&d);

    a[p]=d;
    printf("New array after updating at position %d is : \n\t",p);
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }

    return 0;
}
