/*
	Tree Edge: 	arrival[u] < arrival[v]		departure[u] > departure[v]
	Back Edge: 	arrival[u] > arrival[v]		departure[u] < departure[v]
	Forward edge : 	arrival[u] < arrival[v]		departure[u] > departure[v]
	Cross edge : 	arrival[u] > arrival[v]		departure[u] > departure[v]
	
	Back Edge in DFS => Cycle in Directed Graph
	Cross Edge in BFS => Cycle in Undirected Graph
*/




#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void dfs(int u, int visited[], vector<int> AL[], int parent[])
{
	visited[u] = 1;
	
	vector<int> neighbors = AL[u]; 
	for(int i=0; i<neighbors.size(); i++)
	{
		if(visited[neighbors[i]]==0)
		{
			parent[neighbors[i]] = u;
			dfs(neighbors[i],visited,AL,parent);
		}
		else if(visited[neighbors[i]]==1)
		{
			if(neighbors[i]==parent[u])
				cout<<"Bidirectional : "<<u<<"->"<<neighbors[i]<<" "<<neighbors[i]<<"->"<<u<<endl;	//Loop
			else
				cout<<"Back Edge :"<<u<<"->"<<neighbors[i]<<endl;		//Back Edge in DFS means CYCLE in DIRECTED graph
		}
		else if(visited[neighbors[i]]==2)
		{
			cout<<"Forward/Cross edge :"<<u<<"->"<<neighbors[i]<<endl;
		}
	}
	visited[u] = 2;
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
	
	int visited[nodes] = {0};	//0,1,2
	int parent[nodes] = {-1};
	int numCC=0;
	
	for(i=0; i<nodes; i++)
	{
		if(!visited[i])
		{
			numCC++;
			dfs(i,visited,AL,parent);
		}
	}
	cout<<"no of connected components : "<<numCC<<endl;
	return 0;
}
