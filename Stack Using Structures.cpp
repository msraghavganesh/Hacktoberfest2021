#include<iostream>


#define MAX_SIZE 10

using namespace std;
struct stack
{
    char st[MAX_SIZE];
    int top;
};

void display(struct stack* s)
{
    if(s->top==-1)
    {
        cout<<"Stack is empty";
    }
    else
    {
        cout<<"Elements of stack are: ";
        for(int i=s->top; i>=0; i--)
        {
            cout<<s->st[i]<<" ";
        }
    }
    cout<<"\n\n";
}

void pop(struct stack* s)
{
    if (s->top==-1)
    {
        cout<<"Stack is empty";
    }
    else
    {
        char temp=s->st[s->top];
        s->top--;
        cout<<"Element "<<temp<<" has been poped out of stack";
    }
}

void push(struct stack* s,char item)
{
    if(s->top==MAX_SIZE-1)
    {
        cout<<"Stack is full\n\n";
    }
    else
    {
        s->top++;
        s->st[s->top]=item;
        cout<<"Push sucesssful\n\n";
    }
}

void top(struct stack* s)
{
    cout<<"Top element is "<<s->st[s->top]<<" and top points at"<<s->top<<"\n\n";
}



int main()
{
    int choice;
    char element;
    struct stack s1;
    s1.top=-1;
    

    while(true)
    {
    cout<<"Select choice."<<endl;
    cout<<"1. Display stack."<<endl;
    cout<<"2. Pop element."<<endl;
    cout<<"3. Push element."<<endl;
    cout<<"4. Top element."<<endl;
    cout<<"5. Exit."<<endl;
    cout<<"\n\n";
    cin>>choice;
    if (choice==1)
    {
        display(&s1);
    }
    else if(choice==2)
    {
        pop(&s1);
    }
    else if (choice==3)
    {
        cout<<"Enter element to be pushed into stack: ";
        cin>>element;
        push(&s1,element);
    }
    else if(choice==4)
    {
        top(&s1);
    }
    else if(choice==5)
    {
        break;
    }
    else{
        cout<<"Invalid choice";
    }
    }
}