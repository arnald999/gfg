#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>
using namespace std;

int knapSack(int v[], int w[], int n, int W, vector<int> &item)
{
	int table[n+1][W+1];
	
	for(int j=0; j<=W; j++)
		table[0][j] = 0;
	
	for(int i=1; i<=n ;i++)
	{
		for(int j=0; j<=W; j++)
		{
			if(w[i-1]>j)
				table[i][j] = table[i-1][j];
			else
			{
				if(table[i-1][j] > table[i-1][j-w[i-1]]+v[i-1])
					table[i][j] = table[i-1][j];
				else
				{
					table[i][j] = table[i-1][j-w[i-1]] + v[i-1];
					item.push_back(w[i-1]);
				}
				//table[i][j] = max(table[i-1][j],  table[i-1][j-w[i-1]] + v[i-1]);
			}
		}
	}
	return table[n][W];
}

// 0-1 Knapsack problem
int main()
{
	// Input: set of items each with a weight and a value
	int v[] = { 20, 5, 10, 40, 15, 25 };
	int w[] = {  1, 2,  3,  8,  7, 4 };

	// Knapsack capacity
	int W = 10;

	// number of items
	int n = sizeof(v) / sizeof(v[0]);
	vector<int> item;
	cout << "Knapsack value is " << knapSack(v, w, n - 1, W, item)<<endl;
	
	for(auto &i:item)
	{
		cout<<i<<" ";
	}
	cout<<endl;

	return 0;
}
