#include<stdio.h>
#include<stdlib.h>

struct array{
    int *A;
    int size;
};

void swap(int *x,int *y)
{
 int temp=*x;
 *x=*y;
 *y=temp;
}

int Partition(int B[],int l,int h){
    int Pivot=B[l];
    int i=l,j=h;
    do{
    do{i++;}while(B[i]<=Pivot);
    do{j--;}while(B[j]>Pivot);
    if(i<j){
    swap(&B[i],&B[j]);}
}while(i<j);
swap(&B[l],&B[j]);
return j;
}

void QuickSort(int B[],int l,int h){
    int j;
    if(l<h){
        j=Partition(B,l,h);
        QuickSort(B,l,j);
        QuickSort(B,j+1,h);
    }
}

int main(){
int B[]= {11,13,7,12,16,9,24,5,10,3,__INT32_MAX__};

QuickSort(B,0,10);

for (int i = 0; i < 10; i++)
{
    printf("%d ",B[i]);
}

return 0;

}