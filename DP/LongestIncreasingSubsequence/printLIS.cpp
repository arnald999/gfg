#include <iostream>
#include <vector>
using namespace std;

void findLIS(int arr[], int n)
{
	vector<int> LIS[n];
	int table[n] = {1};
	LIS[0].push_back(arr[0]);
	for(int i=1; i<n; i++)
	{
		for(int j=0; j<i; j++)
		{
			if(arr[j]<arr[i] && table[j]>=table[i])
			{
				table[i] = table[j]+1;
				LIS[i].push_back(arr[j]);
			}
		}
	}
	for(int i=0; i<LIS[n-1].size(); i++)
		cout<<LIS[n-1][i]<<" ";
}


int main()
{
	int arr[] = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };
	int n = sizeof(arr)/sizeof(arr[0]);

	findLIS(arr, n);

	return 0;
}
