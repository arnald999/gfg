#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string,int> lookup;

int LPS(string X, int i, int j)
{
	if(i>j)
		return 0;
	
	if(i==j)
		return 1;
	
	string key = to_string(i)+"|"+to_string(j);
	
	if(lookup.find(key)==lookup.end())
	{
		if(X[i]==X[j])
			lookup[key] = LPS(X,i+1,j-1)+2;
		
		else
			lookup[key] = max(LPS(X,i+1,j), LPS(X,i,j-1));
	}
	return lookup[key];
}

int main()
{	
	string X = "AGTSKMSGTAB";
	
	cout<<LPS(X,0,X.length())<<endl;
	return 0;
}
