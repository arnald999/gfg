#include <iostream>
#include <stack>
using namespace std;

class MyStack
{
	stack<int> s;
	int min;
	
	public:
		void mypush(int x)
		{
			if(s.empty())
			{
				min = x;
				s.push(x);
				cout<<"Pushed : "<<x<<endl;
				return;
			}
			
			if(x<min)
			{
				s.push(2*x-min);
				min = x;
			}
			else
				s.push(x);
			cout<<"Pushed : "<<x<<endl;
		}
		
		void mypop()
		{
			if(s.empty())
			{
				cout << "Stack is empty\n"; 
           			return; 
			}
			int t = s.top();
			s.pop();
			//cout<<"Popped : "<<t<<endl;
			
			if (t < min) 
			{ 
				cout <<"Popped : "<< min << "\n"; 
				min = 2*min - t; 
			} 
		  
			else
				cout <<"Popped : "<< t << "\n"; 
		}
		
		void mypeek()
		{
			if (s.empty()) 
			{ 
				cout << "Stack is empty "; 
				return; 
			} 
			int t = s.top(); 
			
			(t < min)? t = min:t = t; 
			cout<<"Top : "<<t<<endl;
		}
		
		void getmin()
		{
			if (s.empty()) 
				cout << "Stack is empty\n"; 

			else
				cout<<"Min : "<<min<<endl;
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
