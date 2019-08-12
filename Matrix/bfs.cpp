#include <iostream>
#include <queue>
using namespace std;

class Node
{
	public:
		int x,y,dist;
};

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool is_valid(int i, int j, int row, int col, int **layout, bool **visited) {
    return (i>=0 && i<row && j>=0 && j<col && layout[i][j] && (!visited[i][j]));
}

int isPath(int **layout, int row, int col)
{
	if(layout[0][0]==0)
		return 0;
	
	bool **visited;
	visited = new bool*[row];
	
	for(int i=0; i<row; i++)
		visited[i] = new bool[col];
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			visited[i][j] = false;
	
	queue<Node> que;
	Node node = {0,0,0};
	
	que.push(node);
	
	while(!que.empty())
	{
		Node nd = que.front();
		int x = nd.x;
		int y = nd.y;
		int dist = nd.dist;
		
		que.pop();
		
		for(int k=0; k<4; k++)
		{
			if(is_valid(x+dx[k], y+dy[k], row, col, layout, visited))
			{
				visited[x+dx[k]][y+dy[k]] = true;
				//dfs(x+dx[k], y+dy[k], layout, row, col, visited, stk);
				nd = {x+dx[k], y+dy[k], dist+1};
				que.push(nd);
				if(layout[nd.x][nd.y]==9)
				{
					cout<<"Min dist : "<<dist+1<<endl;
					return 1;
				}
			}
		}
	}
	return 0;
}

int main() 
{
	int r,c;
	//int **layout;
	cin >> r >> c;
	int **layout;
	layout = new int*[r]; // dynamic array (size 10) of pointers to int

	for (int i = 0; i < r; ++i) {
	  layout[i] = new int[c];
	}
	// layout[i][j] = 0/1/9
	// 0 = blocked, 1 = path exists, 9 = destination
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
	    		cin >> layout[i][j];
	cout << isPath(layout,r,c) << "\n";
}
