#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// data structure to store graph edges
struct Edge {
	int src, dest;
};

// class to represent a graph object
class Graph
{
public:
	// construct a vector of vectors to represent an adjacency list
	vector<vector<int>> adjList;

	// Graph Constructor
	Graph(vector<Edge> const &edges, int N)
	{
		// resize the vector to N elements of type vector<int>
		adjList.resize(N);

		// add edges to the undirected graph
		for (auto &edge: edges)
		{
			adjList[edge.src].push_back(edge.dest);
			adjList[edge.dest].push_back(edge.src);
		}
	}
};

// Perform BFS on graph starting from vertex v	
bool BFS(Graph const &graph, int v, int N)
{
	// stores vertex is discovered or not
	vector<bool> discovered(N);
	
	// stores level of each vertex in BFS
	vector<int> level(N);
	
	// mark source vertex as discovered and
	// set its level to 0
	discovered[v] = true, level[v] = 0;
	
	// create a queue to do BFS and enqueue
	// source vertex in it
	queue<int> q;
	q.push(v);

	// run till queue is not empty
	while (!q.empty())
	{
		// pop front node from the queue
		v = q.front();
		q.pop();

		// do for every edge (v -> u)
		for (int u : graph.adjList[v])
		{
			// if vertex u is explored for first time
			if (!discovered[u])
			{
				// mark it discovered
				discovered[u] = true;
					// set level as level of parent node + 1
				level[u] = level[v] + 1;
					// push the vertex into the queue
				q.push(u);
			}
			// if the vertex is already been discovered and
			// level of vertex u and v are same, then the
			// graph contains an odd-cycle & is not biparte
			else if (level[v] == level[u])
				return false;
		}
	}
	
	return true;
}

// Determine if a given graph is Bipartite Graph or not
int main()
{
	// vector of graph edges as per above diagram
	vector<Edge> edges = {
		{0,1},{0,2},{0,3},{2,4},{4,0}
		// if we add 2->4 edge, graph is becomes non-Bipartite
	};

	// Number of nodes in the graph
	int N = 5;

	// create a graph from edges
	Graph graph(edges, N);
	
	// Do BFS traversal starting from vertex 1
	if (BFS(graph, 1, N))
		cout << "Bipartite Graph";
	else
		cout << "Not a Bipartite Graph";
	
	return 0;
}
