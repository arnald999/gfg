#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;


class LruCache
{
	list<int> dq;
	unordered_map<int, list<int>::iterator> ma;
	int csize;
	
	public:
		LruCache(int n)
		{
			csize = n;
		}
		
		void refer(int x)
		{
			if(ma.find(x)==ma.end())
			{
				if(dq.size()==csize)
				{
					int last = dq.back();
					dq.pop_back();
					ma.erase(last);
				}
			}
			else
				dq.erase(ma[x]);
			dq.push_front(x);
			ma[x] = dq.begin();
		}
		
		void display()
		{
			for(auto it = dq.begin(); it != dq.end(); it++)
				cout << (*it) << " ";
			cout<<endl;
		}
};

int main() 
{ 
	LruCache ca(4); 

	ca.refer(1); 
	ca.refer(2); 
	ca.refer(3); 
	ca.refer(1); 
	ca.refer(4); 
	ca.refer(5); 
	ca.display(); 
	  
	    return 0; 
}
