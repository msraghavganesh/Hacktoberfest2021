#include<stdio.h>
int main()
{
    int number,q,rem,result=0;

    printf("enter the number:");
    scanf("%d",&number);

    q=number;
    while(q!=0)
    {
        rem=q%10;
        result=result*10+rem;
        q=q/10;
    }
    if(result==number)
    {
        printf("%d is a palindrome number", number);
    }
    else
    {
        printf("%d is not a palindrome number",number);
    }
    return 0;
}