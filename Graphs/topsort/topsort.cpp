#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int u, bool visited[], vector<int> AL[], stack<int> &stk)
{
	if(visited[u])
		return;
	
	//cout<<u<<" ";			//arrival[u]=++time;
	visited[u] = true;	
	vector<int> neighbors = AL[u];
	
	for(int i=0; i<neighbors.size(); i++)
	{
		if(!visited[neighbors[i]])
			dfs(neighbors[i],visited,AL,stk);
	}
	stk.push(u);		//departure[u]=++time;
}


int main()
{
	int nodes,edges,x,y,i;
	
	cin>>nodes>>edges;
	
	
	vector<int> AL[nodes];
	
	for(i=0; i<edges; i++)
	{
		cin>>x>>y;
		AL[x].push_back(y);
	}
	
	bool visited[nodes] = {false};
	stack<int> stk;
	
	for(i=0; i<nodes; i++)
	{
		if(!visited[i])
			dfs(i,visited,AL,stk);
	}
	
	while(!stk.empty())
	{
		cout<<stk.top()<<" ";
		stk.pop();
	}
	return 0;
}
