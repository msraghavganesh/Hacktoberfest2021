#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int myrand()
{
    int i, b;
    srand(time(0));
a:
    b = rand();
    if (b >= 100)
    {
        goto a;
    }

    return b;
}

int main()
{

    int n = 1, i, move, called;
    called = myrand();
    printf("********************************************************\n");
    printf("\t\t\tGame Time \n");
    printf("********************************************************\n");

    printf("Here Computer guessd a number less then 100. \n Now it's your time to match the number in 7 moves.\n");

    while (n <= 7)
    {
        printf("\nGuess your %d moves : ", n);
        n++;

        scanf("%d", &move);

        if (move == called)
        {
            printf("\nYou Won! Your number is matched.");
            break;
        }
        else if (move < called)
        {
            printf("\nYour Number is smaller. Enter a Greater Number --->");
        }
        else
            printf("\nYour Number is Greater. Now enter a smaller Number --->");

        if (n > 7)
        {
            printf("Sorry You Lose. Try Again for the nest time. Dimag laga bacca : :( ");
            printf("\nComputer gussed a %d Number ", called);
            break;
        }
    }

    return 0;
}