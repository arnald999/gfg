#include <iostream>
#include <stack>
using namespace std;

class Node
{
	public:
		int x,y;
};

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool is_valid(int i, int j, int row, int col, int **layout, bool **visited) {
    return (i>=0 && i<row && j>=0 && j<col && layout[i][j] && (!visited[i][j]));
}

void dfs(int x, int y, int **layout, int row, int col, bool **visited, stack<Node> &stk)
{
	Node s = {x,y};
	stk.push(s);
	for(int k=0; k<4; k++)
	{
		if(is_valid(x+dx[k], y+dy[k], row, col, layout, visited))
		{
			visited[x+dx[k]][y+dy[k]] = true;
			dfs(x+dx[k], y+dy[k], layout, row, col, visited, stk);
		}
	}
}


int isPath(int **layout, int row, int col)
{
	if(layout[0][0]==0)
		return 0;
	
	bool **vis;
	vis = new bool*[row];
	
	for(int i=0; i<row; i++)
		vis[i] = new bool[col];
	
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			vis[i][j] = false;

	vis[0][0] = true;
	
	stack<Node> stk;
	Node s = {0,0};
	
	dfs(0,0,layout,row,col,vis,stk);
	
	cout<<"Path : "<<endl;
	while(!stk.empty())
	{
		cout<<stk.top().x<<" "<<stk.top().y<<endl;
		stk.pop();
	}
	cout<<endl<<endl;
	
	for(int i=0; i<row; i++)
		for(int j=0; j<col; j++)
			if(vis[i][j] && layout[i][j]==9)
				return 1;
	return 0;
}

int main() {
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
