
double *arithmetic(int *data, int longData) ;

#include<stdio.h>

 int main( int argc, char *argv[])
 {

    int *line,i;
    double *resultCount;

    int number[] = {1,2,3,4,6,7,8,9,10} ;
    printf("Number : ")   ;
    for (i=0; i < 5; i++) {
        printf("%d ",number[i]);
    }
    line = number;

    resultCount = arithmetic(line,5);
    printf("\nTotal : %.1f \n", *resultCount);
    printf("Average : %.2f \n", *(resultCount+1));

 return 0  ;
 }

double *arithmetic(int *data, int longData)
{
    int i, tot;
    double ave, dtot;
    tot = 0; ave = 0;
    for(i=0;i<longData;i++){
        tot += *(data+i);
    }
    ave = (double)tot/longData ;
    dtot= (double)tot;
    static double result[2];
    result[0] = dtot;
    result[1] = ave;
    return result ;
}