#include <iostream>
#include <climits>
using namespace std;

int findMinCoins(int coins[], int m, int V) 
{ 
    // table[i] will be storing the minimum number of coins 
    // required for i value.  So table[V] will have result 
    int table[V+1]; 
  
    // Base case (If given value V is 0) 
    table[0] = 0; 
  
    // Initialize all table values as Infinite 
    for (int i=1; i<=V; i++) 
        table[i] = INT_MAX; 
  
    // Compute minimum coins required for all 
    // values from 1 to V 
    for (int i=1; i<=V; i++) 
    { 
        // Go through all coins smaller than i 
        for (int j=0; j<m; j++) 
          if (coins[j] <= i) 
          { 
              int sub_res = table[i-coins[j]]; 
              if (sub_res != INT_MAX && sub_res + 1 < table[i]) 
                  table[i] = sub_res + 1; 
          } 
    } 
    return table[V]; 
} 
int main()
{
	// n coins of given denominations
	int S[] = { 1, 2, 3, 4 };
	int n = sizeof(S) / sizeof(S[0]);

	// Total Change required
	int N = 15;

	cout << "Minimum number of coins required to get desired change is "
			<< findMinCoins(S, n, N);

	return 0;
}
