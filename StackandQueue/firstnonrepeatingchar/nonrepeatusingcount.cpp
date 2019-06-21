#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Repeat
{
	public:
		char ch;
		int val;
};

void firstnonrepeat(string s)
{
	unordered_map<char,int> count;
	for(int i = 0; i<s.length(); i++)
	{
		if(count.find(s[i]) != count.end())
			count[s[i]]++;
		else
			count[s[i]] = 1;
	}
	
	for(int i = 0; i<s.length(); i++)
	{
		cout<<s[i]<<" "<<count[s[i]]<<endl;
	}
	//vector<Repeat> db;
	for(int i = 0; i<s.length(); i++)
	{
		if(count[s[i]]==1)
		{
			cout<<endl<<s[i]<<endl;
			break;
		}
	}
}

int main()
{
	string str = "ADBCGHIEFKJLADTVDERFSWVGHQWCNOPENSMSJWIERTFB";
	firstnonrepeat(str);
	return 0;
}
