#include <iostream>
using namespace std;

void generateBitstrings(int i, vector<int> B, int n, vector<vector<int>> bitstrings)
{
	if(i==n)
		bitstrings.push_back(B);
	else
	{
		B[i] == 1
		generateBitstrings(i+1,B,bitstrings);
		B[i] == 0
		generateBitstrings(i+1,B,bitstrings);
	}
		
}

vector<vector<int>> powerset(string str)
{
	int size = str.length();
	vector<int> B(size);
	vector<vector<int>> bitstrings;
	generateBitstrings(0,B,size,bitstrings);
	
	vector<vector<string>> subsets;
	vector<string> bitstring(size);
	
	for(int i =0; i<bitstrings.size(); i++)
	{
		vector<string> subset;
		
		bitstring = bitstrings[i];
		
		for(int i=0; i<size; i++)
		{
			if(bitstring[i]==1)
				subset.push_back
		}
	}
}

int main()  
{  
    string str = "ABC";  
    int n = str.size();  
    permute(str, 0, n-1);  
    return 0;  
}
