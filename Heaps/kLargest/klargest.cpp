#include <iostream>
#include <climits>
using namespace std;

int swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}

class MinHeap
{
	int capacity;
	int heap_size;
	int *harr;
	
		public:
			MinHeap(int cap, int arr[])
			{
				this->capacity = cap;
				this->heap_size = 0;
				this->harr = arr;
				buildheap();
			}
			int parent(int i)
			{
				return (i-1)/2;
			}
			int left(int i)
			{
				return 2*i+1;
			}
			int right(int i)
			{
				return 2*i+2;
			}
			int getmin()
			{
				return harr[0];
			}
			
			void insertkey(int k)
			{
				if(heap_size==capacity)
				{
					cout<<"Overflow"<<endl;
					return;
				}	
				
				heap_size++;
				int i = heap_size-1;
				harr[i] = k;
				
				while(i!=0 && harr[parent(i)]>harr[i])
				{
					swap(harr[parent(i)],harr[i]);
					i = parent(i);
				}
			}
			
			
			
			void MinHeapify(int i)
			{
				int l = left(i);
				int r = right(i);
				int smallest = i;
				
				if(l<heap_size && harr[l]<harr[i])
					smallest = l;
				if(r<heap_size && harr[r]<harr[smallest])
					smallest = r;
				if(smallest != i)
				{
					swap(harr[i], harr[smallest]);
					MinHeapify(smallest);
				}
			}
			int extractmin()
			{
				if(heap_size<=0)
					return INT_MAX;
				
				if(heap_size==1)
				{
					heap_size--;
					return harr[0];
				}
				
				int root = harr[0];
				harr[0] = harr[heap_size-1];
				heap_size--;
				MinHeapify(0);
				
				return root;
			}
			
			
			void decreasekey(int i, int new_value)
			{
				harr[i] = new_value;
				while(i!=0 && harr[parent(i)]>harr[i])
				{
					swap(harr[parent(i)], harr[i]);
					i = parent(i);
				}
			}
			void deletekey(int i)
			{
				decreasekey(i,INT_MIN);
				extractmin();
			}
			
			
			
			
			void buildheap()
			{
				for(int i= heap_size/2-1; i>=0; i--)
				{
					MinHeapify(i);
				}
			}
};


void firstKelements(int arr[], int size, int k)
{
	MinHeap *m = new MinHeap(k,arr);
	
	for(int i = k; i<size; i++)
	{
		if(arr[0]>arr[i])
			continue;
		
		else
		{
			arr[0] = arr[i];
			m->MinHeapify(0);
		}
	}
	
	for(int i=0; i<k; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	int arr[] = { 11, 3, 2, 1, 15, 5, 4, 
                           45, 88, 96, 50, 45 }; 
  
	int size = sizeof(arr) / sizeof(arr[0]); 

	// Size of Min Heap 
	int k = 3; 

	firstKelements(arr,size,k); 

	return 0; 
}
