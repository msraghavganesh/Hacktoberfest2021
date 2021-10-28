#include<stdio.h>
int main()
{
    int number,result=0,fact=1;
    printf("Enter any number: ");
    scanf("%d",&number);

    while(number!=0){
        fact=fact*number;
        number--;
    }
    printf("%d ",fact);
    return 0;
}
