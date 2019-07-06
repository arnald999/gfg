#include <iostream>
using namespace std;

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}


void selectionsort(int arr[], int n)
{
	int min_idx;
	for(int i=0; i<n-1; i++)
	{
		min_idx = i;
		for(int j=i+1; j<n; j++)
		{
			if(arr[j] < arr[min_idx])
				min_idx = j;
		}
		swap(&arr[i],&arr[min_idx]);
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
	selectionsort(arr,size);
	print(arr,size);
	
	return 0;
}
