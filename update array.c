#include <stdio.h>
int main()
{
    int a[100],n,i,d,p;
    printf("Enter the length of array : ");
    scanf("%d",&n);
    printf("Enter the array : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the position and the updated number : ");
    scanf("%d %d",&p,&d);
    printf("New array after updating is : ");
    for(i=0;i<p;i++)
    {
        printf("%d ",a[i]);
    }
    a[p]=d;
    printf("%d ",a[p]);
    for(i=p+1;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
