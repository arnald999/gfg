#include <iostream>
using namespace std;

void removeDuplicate(string str)
{
	char prev = '\0';
	for(auto it=str.begin() ; it!=str.end(); it++)
	{
		if(prev==*it)
		{
			str.erase(it);
			it--;
		}
		else
			prev = *it;
	}
	cout<<str<<endl;
}

int main()
{
	removeDuplicate("aaabbbjddcdc");
	return 0;
}
