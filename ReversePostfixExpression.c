#include<stdio.h>
#define SIZE 100
int top=-1;
int main(){
    int cndn=1,ele,val,size,choice,value;
    int arr[SIZE];
    char a[100];
    int eval(char[],int[]);
    printf("\nEnter your postfix expression");
    scanf("%[^\n]",&a);
    value=eval(a,arr);
    if(value!=-1)
        printf("\nThe Value of the expression is:%d",value);
    else{
        printf("\n INVALID EXPRESSION.. TRY AGAIN");
    }
    return 0;
}
int eval(char a[],int arr[]){
    int i,operand1,operand2,evalValue;
    void push(int[],int);
    int pop(int[]);
    int isEmpty(int[]);
    int operate(int,int,char);
    
    for(i=0;a[i]!='\0';i++){
        if(a[i]>='0'&& a[i]<='9'){
            push(arr,a[i]-'0');
        }else if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/'||a[i]=='%'){
            if(!isEmpty(arr))
                operand2=pop(arr);
            else
                return -1;//not containing enough operands
            if(!isEmpty(arr))
                operand1=pop(arr);
            else
                return -1;//not containing enough operands
            evalValue=operate(operand1,operand2,a[i]);
            push(arr,evalValue);
        }else
            return -1;//for any other character other than any operands or operators
    }
    if(i<=1)
        return -1;//if it contains only a single character or no character
    evalValue=pop(arr);
    if(!isEmpty(arr))
        return -1;//if the stack is not empty
    return evalValue;
}
int operate(int oper1,int oper2,char op){
    switch(op){
        case '+':return oper1+oper2;
        case '-':return oper1-oper2;
        case '*':return oper1*oper2;
        case '/':return oper1/oper2;
        case '%':return oper1%oper2;
    }
    return -1;
}
void push(int arr[],int ele){
    if(top==SIZE-1){
        printf("STACK FULL");
        return;
    }
    arr[++top]=ele;
}
int pop(int arr[]){
    if(top==-1){
        printf("STACK EMPTY");
        return -1;
    }
    return arr[top--];
}
int isEmpty(int ar[]){
    if(top==-1)
        return 1;
    return 0;
}
