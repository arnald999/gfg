#include <iostream>
#include<stack>
#include<queue>
using namespace std;

int main() {

    int i,k,g,h;
    stack<int>s;
    queue<int>q;
    string s1,q1;
    cin.ignore();
    getline(cin,s1);
    cin.ignore();
    getline(cin,q1);
    for(i=0;i<s1.size();i++)
    {
        s.push(s1[i]);
    }
    for(i=0;i<q1.size();i++)
    {
        q.push(q1[i]);
    }
    
    int count = 0;
    while(!s.empty() && count<=s1.size())
    {
        if(q.front()!=s.top())
        {
            k=q.front();
            q.pop();
            q.push(k);
            count++;
        }
        else
        {
            q.pop();
            s.pop();
            count =0;
        }
    }
    cout<<q.size();
    return 0;
}
