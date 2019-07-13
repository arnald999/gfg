/*
	Bipartite if and only if:
		DFS - it is 2-colorable, current vertex to the next(or prev) vertex as different colour
		BFS - it does not contain an odd cycle, if we find an Edge in BFS which are in the same level
			level of vertex = min dist from stating vertex
*/


#include <iostream>
#include <queue>
#include <vector>
using namespace std;


bool bfs(int u, int n, bool visited[], vector<int> AL[])
{
	int level[n] = {0};
	
	visited[u] = true;
	level[u] = 0;
	
	queue<int> q;
	q.push(u);
	
	while(!q.empty())
	{
		u = q.front();
		q.pop();
		 
		vector<int> neighbors = AL[u];
		
		for(int i=0; i<neighbors.size(); i++)
		{
			if(!visited[i])
			{
				visited[i] = true;
				level[i] = level[u] + 1;
				q.push(i);
			}
			else if(level[u]==level[i])
				return false;
		}	
	}
	return true;
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
	
	if(bfs(start_node,nodes,visited,AL))
		cout<<"Bipartite"<<endl;
	else
		cout<<"Not Bipartite"<<endl;
		
	return 0;	
}



