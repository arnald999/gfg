#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void printMincost(int arr[], int n)
{
    priority_queue<int, vector<int>, greater<int>> qp;
    for(int i=0; i<n; i++)
    {
        qp.push(arr[i]);
        cout<<"queue"<<qp.top()<<" ";
    }
    cout<<endl;
    
    int res;
    while(!qp.empty())
    {
        int x = qp.top();
        qp.pop();
        int y = qp.top();
        qp.pop();
        res = x+y;
        qp.push(res);
        if(qp.size()==1)
            break;
    }
    cout<<res<<endl;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0; i<n; i++)
	    {
	        cin>>arr[i];
	    }
	    printMincost(arr,n);
	}
	return 0;
}
