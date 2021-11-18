#include<stdio.h>
int main()
{
    int a,q=1,fact=1;
    printf("Enter any number: ");
    scanf("%d",&a);

    while(q<=a){
        fact=fact*q;
        q++;
    }
    printf("The factorial of the number : %d ",fact);
    return 0;
}
