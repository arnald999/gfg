#include <iostream>
#define MAX 20
using namespace std;


int table[MAX][MAX];
int LCS(string X, string Y, int m, int n)
{
	//int table[m+1][n+1];
	
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

string LCSpath(string X, string Y, int m, int n)
{
	if(m==0 || n==0)
		return "";
	
	if(X[m-1]==Y[n-1])
		return LCSpath(X,Y,m-1,n-1)+X[m-1];
	
	if(table[m-1][n]>table[m][n-1])
		return LCSpath(X,Y,m-1,n);
	else
		return LCSpath(X,Y,m,n-1);
}


int main()
{	
	string X = "AGGTAB";
	string Y = "GXTXAYB";
	int m = X.length();
	int n = Y.length();
	
	cout<<LCS(X,Y,m,n)<<endl;
	cout<<LCSpath(X,Y,m,n)<<endl;
	return 0;
}
