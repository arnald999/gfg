#include <iostream>
using namespace std;

int findLIS(int arr[], int n)
{
	int table[n] = {1};
	for(int i=1; i<n; i++)
	{
		for(int j=0; j<i; j++)
		{
			if(arr[j]<arr[i] && table[j]>=table[i])
				table[i] = table[j]+1;
		}
	}
	return table[n-1];
}


int main()
{
	int arr[] = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };
	int n = sizeof(arr)/sizeof(arr[0]);

	cout<<findLIS(arr, n);

	return 0;
}
