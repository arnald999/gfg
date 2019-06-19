#include <iostream>
#include <stack>
using namespace std;

class MyStack
{
	stack<int> s,smin;
	//int min;
	
	public:
		void mypush(int x)
		{
			if(s.empty())
			{
				//min = x;
				s.push(x);
				smin.push(x);
				cout<<"Pushed : "<<x<<endl;
				return;
			}
			
			int min = smin.top()<x?smin.top():x;
			smin.push(min);
			s.push(x);
			cout<<"Pushed : "<<x<<endl;
		}
		
		void mypop()
		{
			if(s.empty())
			{
				cout<<"Stack is empty"<<endl;
				return;
			}
			
			int t = s.top();
			s.pop();
			cout<<"Popped : "<<t<<endl;
			smin.pop();
		}
		
		void mypeek()
		{
			if(s.empty())
			{
				cout<<"Stack is empty"<<endl;
				return;	
			}
			cout<<"Top : "<<s.top()<<endl;
		}
		
		void getmin()
		{
			if(s.empty())
			{
				cout<<"Stack is empty"<<endl;
				return;	
			}
			cout<<"Min : "<<smin.top()<<endl;
		}
};

int main() 
{ 
	MyStack s; 
	s.mypush(3); 
	s.mypush(5); 
	s.getmin(); 
	s.mypush(2); 
	s.mypush(1); 
	s.getmin(); 
	s.mypop(); 
	s.getmin(); 
	s.mypop(); 
	s.mypeek(); 

	return 0; 
} 
