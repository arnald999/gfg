#include<bits/stdc++.h> 
using namespace std; 
 
int prec(char c)
{
	if(c=='^')
		return 3;
	else if(c=='*' || c=='/')
		return 2;
	else if(c=='+' || c=='-')
		return 1;
	else
		return -1;
}
 
void infixToPostfix(string s)
{
	stack<char> st;
	string res = "";
	for(int i=0; i<s.length(); i++)
	{
		if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
			res = res+s[i];
		
		else if(s[i]=='(')
			st.push('(');
		
		else if(s[i]==')')
		{
			while(!st.empty() && st.top()!='(')
			{
				res = res+st.top();
				st.pop();
			}
			if(st.top()=='(')
				st.pop();
		}
		else
		{
			while(!st.empty() && prec(s[i])<=prec(st.top()))
			{
				res = res+st.top();
				st.pop();
			}
			st.push(s[i]);
		}
	}
	
	while(!st.empty())
	{
		res = res+st.top();
		st.pop();
	}
	
	cout<<res<<endl;
}


int main() 
{ 
    string exp = "a+b*(c^d-e)^(f+g*h)-i"; 
    infixToPostfix(exp); 
    return 0; 
} 
//
