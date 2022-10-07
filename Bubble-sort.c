#include <stdio.h>
#include <stdlib.h>

int list[10] = {1,8,4,6,0,3,5,2,7,9};

void display() {
    for(int i=0; i<10; i++) {
        printf("%d ",list[i]);
    }
    printf("\n");
}

void sort() {
    for(int i=0; i<10; i++) {
        for(int j=i+1; j<10; j++) {
            if(list[j] < list[i]) {
                int temp = list[j];
                list[j] = list[i];
                list[i] = temp;
            }
        }
    }
    display();
}

int main() {
    // without sort
    display();
    printf("\n after bubble sort : \n");
    sort();
}
