#include <iostream> 
#include <stack> 
using namespace std; 
  
bool isOperator(char c)
{
	return c=='+' || c=='-' || c=='/' || c=='*';
}  

string postToPre(string post_exp)
{
	stack<string> st;
	
	for(int i=0; i<post_exp.length(); i++)
	{
		if(isOperator(post_exp[i]))
		{
			string op1 = st.top();
			st.pop();
			string op2 = st.top();
			st.pop();
			
			string temp = post_exp[i]+op2+op1;
			st.push(temp);
		}
		else
		{
			st.push(string(1,post_exp[i]));
		}
	}
	return st.top();
}
 
int main() 
{ 
    string post_exp = "ABC/-AK/L-*"; 
    cout << "Prefix : " << postToPre(post_exp); 
    return 0; 
} 
