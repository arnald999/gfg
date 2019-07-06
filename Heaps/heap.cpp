#include <iostream>
#include <climits>
using namespace std;

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

class MinHeap
{
	int *harr;	//Array
	int capacity;
	int heap_size;
	
	public:
		MinHeap(int cap)
		{
			heap_size = 0;
			capacity = cap;
			harr = new int[cap];
		}
		
		int parent(int i)
		{
			return (i-1)/2;
		}
		
		int left(int i)
		{
			return (2*i+1);
		}
		
		int right(int i)
		{
			return (2*i+2);
		}
		int getmin()
		{
			return harr[0];
		}
		
		
		void insertkey(int k)
		{
			if(heap_size == capacity)
			{
				cout<<"Overflow"<<endl;
				return;
			}
			
			heap_size++;
			int i = heap_size-1;
			harr[i] = k;
			
			while(i != 0 && harr[parent(i)] > harr[i])
			{
				swap(&harr[i], &harr[parent(i)]);
				i = parent(i);
			}
		}
		
		
		
		void MinHeapify(int i)
		{
			int l = left(i);
			int r = right(r);
			int smallest = i;
			
			// If left child is smaller than root
			if(l<heap_size && harr[l]<harr[smallest])
				smallest = l;
				
			// If right child is smaller than smallest so far
			if(r<heap_size && harr[r]<harr[smallest])
				smallest = r;
			
			if(smallest != i)
			{
				swap(&harr[i],&harr[smallest]);
				MinHeapify(smallest);
			}
			
		}
		int extractmin()
		{
			if(heap_size <= 0)
				return INT_MAX;
			
			if(heap_size == 1)
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
		
		
		
		
		
		
		void decreasekey(int i, int new_val)
		{
			harr[i] = new_val;
			while(i != 0 && harr[parent(i)] > harr[i])
			{
				swap(&harr[i], &harr[parent(i)]);
				i = parent(i);
			}
		}
		void deletekey(int i)
		{
			decreasekey(i, INT_MIN);
			extractmin();
		}
		
};


int main()
{
	MinHeap h(11); 
	h.insertkey(3);
	cout <<h.getmin()<<endl; 
	h.insertkey(2); 
	cout <<h.getmin()<<endl;
	h.deletekey(1); 
	h.insertkey(15); 
	cout <<h.getmin()<<endl;
	h.insertkey(5); 
	cout <<h.getmin()<<endl;
	h.insertkey(4); 
	cout <<h.getmin()<<endl;
	h.insertkey(45); 
	cout <<h.getmin()<<endl;
	h.decreasekey(2, 1); 
	cout << h.getmin()<<endl;
	return 0;
}
