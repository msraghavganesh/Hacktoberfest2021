// c program to print the array elements using recursion.
#include <stdio.h>
#define MAX_SIZE 100

// Function declaration 
void printArray(int arr[], int start, int len);


int main()
{
    int arr[MAX_SIZE];
    int N, i;
    
    // Input size and elements in array 
    printf("Enter size of the array: ");
    scanf("%d", &N);
    printf("Enter elements in the array: ");
    for(i=0; i<N; i++) 
    {
        scanf("%d", &arr[i]);
    }
        
    //  Prints array recursively 
    printf("Elements in the array: ");
    printArray(arr, 0, N);
    
    return 0;
}



//  Prints an array recursively within a given range.
 
void printArray(int arr[], int start, int len)
{
    //  Recursion base condition 
    if(start >= len)
        return;
        
    //  Prints the current array element 
    printf("%d, ", arr[start]);
    
    //  Recursively call printArray to print next element in the array 
    printArray(arr, start + 1, len); 
}