#include <iostream>
using namespace std;

string LCSuffix(string X, string Y, int m, int n)
{
	int maxlen = 0;
	int endingidx = 0;
	
	int table[m+1][n+1];
	
	for(int i=0; i<=m; i++)
		table[i][0] = 0;
	
	for(int j = 0; j<=n; j++)
		table[0][j] = 0;
		
	for(int i=1; i<=m; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(X[i-1] == Y[j-1])
			{
				table[i][j] = table[i-1][j-1] + 1;
				if(maxlen < table[i][j])
				{
					maxlen = table[i][j];
					endingidx = i;
				}
			}
		}
	}
	return X.substr(endingidx-maxlen,maxlen);
}

int main()
{
	string X = "ABC", Y = "BABA";
	int m = X.length(), n = Y.length();

	// Find Longest common substring
	cout << "The Longest common substring is " << LCSuffix(X, Y, m, n);

	return 0;
}
