#include<stdio.h>  
int change(int num) {    
    printf("Before adding value inside function num=%d \n",num);    
    num=num+100;    
    printf("After adding value inside function num=%d \n", num);
    return(num);
}    
int main() {    
    int x=100,b;    
    printf("Before function call x=%d \n", x);    
    b=change(x);//passing value in function    
    printf("After function call x=%d \n",b);    
return 0;  
}    
