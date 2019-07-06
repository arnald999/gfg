#include <iostream>
using namespace std;

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void heapify(int arr[], int n, int i)
{
	int left = 2*i+1;
	int right = 2*i+2;
	int largest = i;	//int smallest = left
	
	if(left<n && arr[left]>arr[largest])
		largest = left;
	
	if(right<n && arr[right]>arr[largest])
		largest = right;
		
	if(largest!=i)
	{
		swap(&arr[i],&arr[largest]);
		heapify(arr,n,largest);
	}
}

void heapsort(int arr[], int n)
{
	for(int i=n/2-1; i>=0; i--)
		heapify(arr,n,i);
	
	for(int i = n-1; i>=0; i--)
	{
		swap(&arr[0],&arr[i]);
		heapify(arr,i,0);
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
	heapsort(arr,size);
	print(arr,size);
	
	return 0;
}
