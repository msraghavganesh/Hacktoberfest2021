#include<stdio.h>

void Merge_Sort(int Ar1[],int Ar2[],int m,int N)
{
  int i,j,k,l,temp,Sorted_Array[100];
  for(k=1;k<m;i++)
  {
  	for(i=0;i<m-1;i++)
	{
		for(j=1;j<m;j++)
		{
			if(Ar1[i]>Ar1[j])
			{
				temp=Ar1[i];
				Ar1[i]=Ar1[j];
				Ar1[j]=temp;
			}
			if(Ar2[i]>Ar2[j])
			{
				temp=Ar2[i];
				Ar2[i]=Ar2[j];
				Ar2[j]=temp;
			}
		}
	}
  }
	for(i=j=k=0;k<=N;)
	{
		if(Ar1[i]<=Ar2[j])
		   Sorted_Array[k++]=Ar1[i++];
		else
		   Sorted_Array[k++]=Ar2[j++];
		if(i==m)
		{
			for(l=k;l<N;l++)
			   Sorted_Array[l]=Ar2[j++];
		}
		else if(j==m)
		{
			for(l=k;l<N;l++)
			   Sorted_Array[l]=Ar1[k++];
		}

	}
	/*for(;j<=m;)
	   Sorted_Array[i++]=Ar1[j++];
	for(;k<=m;)
	   Sorted_Array[i++]=Ar2[k++];*/

	printf("\nThe sorted array after sorting using Merge Sort method is: ");
	for(i=0;i<N;i++)
	    printf(" %d",Sorted_Array[i]);


}


int main()
{
	int n,Array[100],SubAr1[50],SubAr2[50],beg,end,mid,i,j;

	printf("Enter the size of the array: ");
	scanf("%d",&n);

	printf("\nEnter the array elements: ");
	for(i=0;i<n;i++)
		scanf("%d",&Array[i]);

	printf("\nThe original array is:  ");
	for(i=0;i<n;i++)
		printf(" %d",Array[i]);

	beg=0;
	end=n-1;
	mid=n/2;

	for(i=0;i<mid;i++)
	    SubAr1[i]=Array[i];
    printf("\nSub-Array 1:  ");
    for(i=0;i<mid;i++)
        printf(" %d ",SubAr1[i]);

	for(i=0,j=mid;i<=mid,j<=end;i++,j++)
            SubAr2[i]=Array[j];
    printf("\nSub-Array 2:  ");
    for(i=0;i<=mid;i++)
        printf(" %d ",SubAr2[i]);

	Merge_Sort(SubAr1,SubAr2,mid,n);


    return 0;
}
