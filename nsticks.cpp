#include <iostream>
#include <climits>
using namespace std;


int findcosts(int lengths[], int costs[], int n)
{
	int max_val = lengths[0], min_val = lengths[0];
	for(int i=0; i<n; i++)
	{
		max_val = max(max_val, lengths[i]);
		min_val = min(min_val, lengths[i]);
	}
	//cout<<max_val<<" "<<min_val<<endl;
	int cost,mincost = INT_MAX;
	for(int i=min_val; i<=max_val; i++)
	{
		cost = 0;
		for(int j=0; j<n; j++)
			cost+=(abs(lengths[j]-i)*(costs[j]));
		
		mincost = min(mincost,cost);
		//cout<<mincost<<endl;
	}
	return mincost;
}


int main()
{
	int lengths[] = {5,10,15};
	int costs[] = {3,7,8};
	int n =3;
	cout<<findcosts(lengths,costs,n)<<endl;
	return 0;
} 
