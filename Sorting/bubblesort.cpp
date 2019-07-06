#include <iostream>
using namespace std;

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void bubblesort(int arr[], int n)
{
	for(int i = 0; i<n-1 ;i++)
	{
		for(int j = 0; j<n-i-1; j++)
		{
			if(arr[j]>arr[j+1])
				swap(&arr[j],&arr[j+1]);
		}
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
	bubblesort(arr,size);
	print(arr,size);
	
	return 0;
}
