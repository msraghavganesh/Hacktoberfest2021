#include <stdio.h>
int main()
{
    int a[100],n,i,j,t;
    printf("Enter the length of array : ");
    scanf("%d",&n);
    printf("Enter the array : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]<a[j])
            {
            t=a[j];
            a[j]=a[i];
            a[i]=t;
            }
        }
    }    
    printf("Maximum : %d and Minimum : %d",a[0],a[n-1]); 
    return 0;
}
