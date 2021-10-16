#include<stdio.h>

int main()
{
    char arr1[6]="hello";
    char arr2[6];
    int j=4;
    for(int i=0; i<5; i++) {
        arr2[j]=arr1[i];
        j++;
    }
    for(int i=0; i<5; i++) {
        arr1[i]=arr2[i];
    }
    for(int j=0; j<5; j++) {
        printf("%c", arr1[j]);
    }
    return 0;
}