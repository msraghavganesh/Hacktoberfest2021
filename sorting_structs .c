#include <stdio.h>
#include <stdlib.h>
 
struct Student 
{
    int rollno; // Given
    int mth;  // Marks in MTH101 (Given)
    int phy;   // Marks in PHY103 (Given)
    int esc;   // Marks in ESC101 (Given)
    int total; // Total marks (To be filled)
};  
 

int compare(struct Student a, struct Student b){
    // If total marks are not same then
    // returns true for higher total
    if (a.total != b.total )
        return a.total > b.total;

    if (a.mth != b.mth)
            return a.mth > b.mth;

    if (a.esc != b.esc)
            return a.esc > b.esc;

    return a.phy > b.phy;

}

// Fills total marks and ranks of all Students
void computeRanks(struct Student students[], int n)
{
	int i,j;
    // To calculate total marks for all Students
    for (i=0; i<n; i++)
        students[i].total = students[i].mth + students[i].phy + students[i].esc;

    struct Student temp;
 
    for(i=0;i<n;i++){
    	for(j=i+1;j<n;j++){
    		if(!compare(students[i],students[j])){
    			temp = students[i];
    			students[i]= students[j];
    			students[j]=temp;
    		}
    	}
    }
}


int main(){
	int n,i;
	scanf("%d", &n);
	struct Student students[n];

	for(i = 0;i<n;i++){
		scanf("%d",&students[i].rollno);
		scanf("%d",&(students[i].mth));
		scanf("%d",&(students[i].esc));
		scanf("%d",&(students[i].phy));
	}

	computeRanks(students,n);
	for (i=0; i<n; i++)
        printf("%d,%d\n",i+1,students[i].rollno);
}
