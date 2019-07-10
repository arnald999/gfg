//Graph must be UNDIRECTED

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int u, bool visited[], vector<int> AL[])
{
	stack<int> s;
	s.push(u);
	
	vector<int> neighbors;
	
	visited[u] = true;
	while(!s.empty())
	{
		int t = s.top();
		s.pop();
		cout<<t<<" ";
		neighbors = AL[t];
		
		for(int i=neighbors.size()-1; i>=0; i--)
		{
			if(!visited[neighbors[i]])
			{
				visited[neighbors[i]] = true;
				s.push(neighbors[i]);
			}
		}
	}
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
