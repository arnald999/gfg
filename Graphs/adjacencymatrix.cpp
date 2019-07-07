#include <iostream>
using namespace std;

int main()
{
	int x,y,nodes,edges;
	cin>>nodes;
	cin>>edges;
	
	int graph[nodes][nodes] = {{0}};
	
	for(int i=0; i<edges; ++i)
	{
		cin>>x>>y;
		graph[x][y] = graph[y][x] = 1;
	}
	
	for(int i=0; i<nodes; i++)
	{
		cout << "Adjacency list of node " << i << ": ";
		for(int j = 0; j< nodes; ++j)
		{
			if(graph[i][j]==1)
                    		cout << j << endl;
		}
	}
	return 0;
		
}
