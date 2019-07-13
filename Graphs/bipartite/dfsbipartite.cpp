#include <iostream>
#include <vector>
using namespace std;

// Data structure to store graph edges
struct Edge {
	int src, dest;
};

// Class to represent a graph object
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

// Perform DFS on graph starting from vertex v
bool DFS(Graph const &graph, int v, vector<bool> &discovered,
			vector<int> &color)
{
	// do for every edge (v -> u)
	for (int u : graph.adjList[v])
	{
		// if vertex u is explored for first time
		if (!discovered[u])
		{
			// mark current node as discovered
			discovered[u] = true;

			// set color as opposite color of parent node
			color[u] = !color[v];

			// if DFS on any subtree rooted at v
			// we return false
			if (!DFS(graph, u, discovered, color))
				return false;
		}
		// if the vertex is already been discovered and color of vertex
		// u and v are same, then the graph is not Bipartite
		else if (color[v] == color[u]) {
			return false;
		}
	}

	return true;
}

// Determine if a given graph is Bipartite Graph using DFS
int main()
{
	// vector of graph edges as per above diagram
	vector<Edge> edges = {
		{1, 2}, {2, 3}, {2, 8}, {3, 4}, {4, 6}, {5, 7},
		{5, 9}, {8, 9}, {2, 4}
		// if we remove 2->4 edge, graph is becomes Bipartite
	};

	// Number of nodes in the graph
	int N = 10;

	// create a graph from edges
	Graph graph(edges, N);

	// stores vertex is discovered or not
	vector<bool> discovered(N);

	// stores color 0 or 1 of each vertex in BFS
	vector<int> color(N);

	// mark source vertex as discovered and
	// set its color to 0
	discovered[0] = true, color[0] = 0;

	// start DFS traversal from any node as graph
	// is connected and undirected
	if (DFS(graph, 1, discovered, color))
		cout << "Bipartite Graph";
	else
		cout << "Not a Bipartite Graph";

	return 0;
}
