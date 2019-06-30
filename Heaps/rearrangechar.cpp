#include <iostream>
#include <queue>
#include <string>
using namespace std;

const int MAX_CHAR = 26;

class MyKey
{
	public:
		int freq;
		char ch;
};


//template <class T>
class myComp
{
	public:
		bool operator()(const MyKey &first, const MyKey &second)
		{
			return first.freq<second.freq;
		}
};

void rearrange(string str)
{
	int n = str.length();
	
	int count[MAX_CHAR] = {0};
	for(int i=0; i<n; i++)
		count[str[i]-'a']++;
	/*
	for(int j =0; j<n; j++)
		cout<<count[str[j]-'a']<<endl;
	*/
	priority_queue<MyKey, vector<MyKey>, myComp> pq;
	
	for(char c = 'a'; c<='z'; c++)
		if(count[c-'a'])
			pq.push(MyKey{count[c-'a'],c});
		
	/*	
	while(!pq.empty())
	{
		cout<<pq.top().ch<<" "<<pq.top().freq<<endl;
		pq.pop();
	}
	*/
	str = "";
	
	MyKey prev{-1,'#'};
	while(!pq.empty())
	{
		MyKey k = pq.top();
		pq.pop();
		str = str + k.ch;
		
		if(prev.freq>0)
			pq.push(prev);
		
		k.freq--;
		prev = k;
	}
	
	if(n != str.length())
		cout << " Not valid String " << endl;
	else
		cout << str << endl;
}

int main()
{
	string str = "bbbaa" ; 
	rearrange(str); 
	return 0;
}
