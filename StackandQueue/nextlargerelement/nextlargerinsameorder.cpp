#include <iostream>
#include <stack>
using namespace std;

void nextlarger(int arr[], int n)
{
	int arr1[n];

	stack<int> s;
	
	for(int i=n-1; i>=0; i--)
	{
		while (!s.empty() && s.top() < arr[i]) 
           		s.pop(); 
		if(s.empty())
			arr1[i] = -1;
		else
			arr1[i] = s.top();
		
		s.push(arr[i]);
	}
	
	for (int i = 0; i < n; i++) 
        	cout << arr[i] << " ---> " << arr1[i] << endl; 
}

int main()
{
	int arr[] = {11, 13, 21, 3}; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	nextlarger(arr, n); 
	return 0;
}
