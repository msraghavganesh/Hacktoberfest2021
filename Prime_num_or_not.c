#include<stdio.h>
int main()
{
    int a,i;
    printf("Enter any +ve number:");
    scanf("%d",&a);

    i=2;
    while (i<=a/2)
    {
        if(a%i==0)
        break;
        i++;
    }
    if(i>a/2)
        printf("%d is a prime number", a);
    else
    {
        printf("%d is not a prime number.", a);
    }
}