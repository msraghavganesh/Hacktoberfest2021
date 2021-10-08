#include<stdio.h>
int main()
{
    int number,result=0,rem,fact=1;
    printf("Enter any number:");
    scanf("%d",&number);

    int q=number;
    while(q!=0){
        fact=fact*q;
        q--;
    }
    printf("%d ",fact);
}