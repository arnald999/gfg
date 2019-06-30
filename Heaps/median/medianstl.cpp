#include <iostream>
#include <queue>
using namespace std;

void runningmedian(double arr[], int n)
{
	priority_queue<double> s;	//Max Heap -> Lower half
	priority_queue<double,vector<double>,greater<double> > g;	//Min Heap -> Higher half

	double med = arr[0];
	s.push(arr[0]);
	
	cout<<"Median : "<<med<<endl;
	
	for(int i=1; i<n ; i++)
	{
		double x = arr[i];
		
		if(s.size() > g.size())
		{
			if(x < med)
			{
				g.push(s.top());
				s.pop();
				s.push(x);
			}
			else
				g.push(x);
			
			med = (s.top()+g.top())/2.0;
		}
		
		else if(s.size() == g.size())
		{
			if(x < med)
			{
				s.push(x);
				med = (double)s.top();
			}
			else
			{
				g.push(x);
				med = (double)g.top();
			}
		}
		
		else
		{
			if(x > med)
			{
				s.push(g.top());
				g.pop();
				g.push(x);
			}
			else
				s.push(x);
			
			med = (s.top()+g.top())/2.0;
		}	
		cout<<"Median : "<<med<<endl;
	}
}

int main() 
{ 
    // stream of integers 
    double arr[] = {5, 15, 10, 20, 3}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    runningmedian(arr, n); 
    return 0; 
} 
