#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;

// create a map to store solutions of subproblems
unordered_map<string, int> lookup;

// Values (stored in array v)
// Weights (stored in array w)
// Number of distinct items (n)
// Knapsack capacity W
int knapSack(int v[], int w[], int n, int W)
{
	if(W<0)
		return INT_MIN;
	
	if(n<0 || W==0)
		return 0;
		
	string key = to_string(n) + "|" + to_string(W);
	
	if(lookup.find(key)==lookup.end())
	{
		int include = v[n] + knapSack(v,w,n-1,W-w[n]);
		int exclude = knapSack(v,w,n-1,W);
		lookup[key] = max(include,exclude);
	}
	return lookup[key];
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

	cout << "Knapsack value is " << knapSack(v, w, n - 1, W);

	return 0;
}
