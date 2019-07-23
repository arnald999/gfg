#include <iostream>
using namespace std;

int LCS(string X, string Y, int m, int n)
{
	int table[m+1][n+1];
	
	for(int i = 0; i<=m; i++)
		table[i][0] = 0;
		
	for(int j = 0; j<=n; j++)
		table[0][j] = 0;
	
	for(int i=1; i<=m; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(X[i-1] == Y[j-1])
				table[i][j] = table[i-1][j-1] + 1;
			else
				table[i][j] = max(table[i-1][j], table[i][j-1]);
		}
	}
	return table[m][n];
}

int main()
{	
	string X = "AGGTAB";
	string Y = "GXTXAYB";
	int m = X.length();
	int n = Y.length();
	
	cout<<LCS(X,Y,m,n)<<endl;
	return 0;
}
