 #include<stdio.h>

#include<conio.h>



void square();

void arithmetic();

void relation();

void mul10();

void odd();

void even();



void main()

{

	int choice;

	

	printf("\n1.square\n");

	printf("\n2.arithmetic operation\n");

	printf("\n3.relational operation\n");

	printf("\n4.multiply with 10\n");

	printf("\n5.odd conversion");

	printf("\6.odd conversion\n");

	printf("enter your choice");

	scanf("%d",&choice);

	switch(choice)

	{

	case 1:

	square();

	break  ;

	

	case 2:

	arithmetic();

	break ;

	  

	 case 3:

	 relation();

	 break ;

	 

	 case 4:

	 mul10();

	 break ;

	 

	 case 5:

	 odd();

	 break ;

	  

	  case 6:

	  even();

	  break ;

	  

	  default:

	  printf("wrong choice");

}



}

void square()

{

	int a,square;

	printf(" enter a number ");

	scanf("%d",&a);

	square=a*a;

	printf("square=%d", square);

}

void arithmetic()

{

	int a,b,add,sub,mul;

	printf("enter the two numbers");

	scanf("%d%d",&a,&b);

	add=a+b;

	sub=a-b;

	mul=a*b;

	printf("addition=%d\n",add);

	printf("subtraction=%d\n",sub);

	printf("multiplicatin=%d",mul);

}



void relation()

{

	int a,b;

	printf("enter the number ");

	scanf("%d%d",&a,&b);

	if(a>b)

	{

		printf("a is large");

	}

	else

	{

		printf("b is large");

	}

}

 void mul10()

 {

 	int a,mul;

 	printf("enter the number");

 	scanf("%d",&a);

 	mul=10*a;

 	printf(" multiply with 10=%d",mul);

 }

 void odd()

 {

 	int a;

 	if(a%2==0)

 	{

 	printf("odd conversion=%d",a++);

 	}

 	else

 	{

 		printf("the number is odd");

 	}

 }

 void even()

 {

 	int a;

 	if(a%2==0)

 	{

 		printf("the number is even");

 	}

 	else

 	{

 		printf("even converion=%d",a++);

 	}

 }
