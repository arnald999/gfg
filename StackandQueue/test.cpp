#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool balancedparenthesis(string str)
{
	stack<char> s;
	char x;
	
	for(int i=0; i<str.length(); i++)
	{
		if(str[i]=='(' || str[i]=='{' || str[i]=='[')
			s.push(str[i]);
		else
		{
			x = s.top();
			s.pop();
			if(!((x=='(' && str[i]==')')||(x=='{' && str[i]=='}')||(x=='[' && str[i]==']')))
				return false;
		}
	}
	return true;
}

int main()
{
	string s = "[({})]";
	bool flag = balancedparenthesis(s);
	if(flag)
		cout<<"BALANCED"<<endl;
	else
		cout<<"NOT BALANCED"<<endl;
	return 0;
}

