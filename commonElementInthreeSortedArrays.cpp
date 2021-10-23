
#include <bits/stdc++.h>
using namespace std;

void findCommon(int ar1[], int ar2[], int ar3[], int n1, int n2, int n3)
{
	int i = 0, j = 0, k = 0;

	while (i < n1 && j < n2 && k < n3)
	{
		if (ar1[i] == ar2[j] && ar2[j] == ar3[k])
		{ cout << ar1[i] << " "; i++; j++; k++; }

		else if (ar1[i] < ar2[j])
			i++;

		else if (ar2[j] < ar3[k])
			j++;

		else
			k++;
	}
}

