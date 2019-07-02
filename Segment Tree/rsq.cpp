#include <bits/stdc++.h>
#include <climits>
using namespace std;


//len(arr) = n		segment tree = 2*n-1
//binary tree		parent = (i-1)/2	left = (2*i+1)		right = (2*i+2)

void constructtree(int input[], int segment[], int low, int high, int pos)
{
	if(low==high)
	{
		segment[pos] = input[low];
		return;
	}
	int mid = (low+high)/2;
	constructtree(input,segment,low,mid,2*pos+1);
	constructtree(input,segment,mid+1,high,2*pos+2);
	segment[pos] = segment[2*pos+1]+segment[2*pos+2];
}

int RSQ(int segment[], int qlow, int qhigh, int low, int high, int pos)
{
	if(qlow<=low && qhigh>=high)
		return segment[pos];
	
	if(qlow>high || qhigh<low)
		return 0;
	
	int mid = (low+high)/2;
	return (RSQ(segment, qlow, qhigh, low, mid, 2*pos+1) + RSQ(segment, qlow, qhigh, mid+1, high, 2+pos+2));
}

int main()
{
	int arr[] = {-1,2,4,0};
	int *segment = new int[7];
	
	constructtree(arr,segment,0,3,0);
	
	cout<<RSQ(segment,1,2,2,3,0)<<endl;
	cout<<RSQ(segment,1,3,0,3,0)<<endl;
	cout<<RSQ(segment,0,2,0,3,0)<<endl;
	return 0;
}

