#include <iostream>
#include <vector>
using namespace std;

void dfs(int u, bool visited[], vector<int> AL[])
{
	if(visited[u])
		return;
	
	cout<<u<<" ";
	visited[u] = true;
	vector<int> neighbors = AL[u];
	
	for(int i=0; i<neighbors.size(); i++)
		dfs(neighbors[i],visited,AL);
}


int main()
{
	int nodes,edges,x,y,i,start_node;
	
	cin>>nodes>>edges;
	
	
	vector<int> AL[nodes];
	
	for(i=0; i<edges; i++)
	{
		cin>>x>>y;
		AL[x].push_back(y);
		AL[y].push_back(x);
	}
	
	bool visited[nodes] = {false};
	
	cout<<"Start node : ";
	cin>>start_node;
	
	dfs(start_node,visited,AL);
	return 0;
}
