#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string,int> lookup;

int LCS(string X, string Y, int m, int n)
{
	if(m==0||n==0)
		return 0;
	
	string key = to_string(m)+"|"+to_string(n);
	
	if(lookup.find(key)==lookup.end())
	{
		if(X[m-1]==Y[n-1])
			lookup[key] = LCS(X,Y,m-1,n-1)+1;
		
		else
			lookup[key] = max(LCS(X,Y,m-1,n), LCS(X,Y,m,n-1));
	}
	return lookup[key];
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
