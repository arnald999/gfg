#include <iostream>
using namespace std;

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}


void insertionsort(int arr[], int n)
{
	for(int i = 1; i<n; i++)
	{
		int key = arr[i];
		int j = i-1;
		while(j>=0 && arr[j]>key)
		{
			arr[j+1] = arr[j];
			j = j-1;
		}
		arr[j+1] = key;
	}
}


void print(int arr[], int n)
{
	for(int i = 0; i<n; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

int main()
{
	int arr[] = {46,56,312,12,65,70};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	print(arr,size);
	insertionsort(arr,size);
	print(arr,size);
	
	return 0;
}
