#include <iostream>
#include <vector>
#include <iomanip>
#define M 10
#define N 10
using namespace std;

int row[] = { -1, -1, -1,  0, 0,  1, 1, 1 };
int col[] = { -1,  0,  1, -1, 1, -1, 0, 1 };

void floodfillUtil(char mat[M][N], int x, int y, char prev, char replacement)
{
	if(x<0 || x>=M || y<0 || y>=N)
		return;
	
	if(mat[x][y] != prev)
		return;
	
	mat[x][y] = replacement;
	
	//recur for each pixel
	for(int k = 0; k<8; k++)
		floodfillUtil(mat,x+row[k],y+col[k],prev, replacement);	
}

void floodfill(char mat[M][N], int x, int y, char replacement)
{
	char prev = mat[x][y];
	floodfillUtil(mat,x,y,prev, replacement);
}

int main()
{
	// matrix showing portion of the screen having different colors
	char mat[M][N] =
	{
		{ 'Y', 'Y', 'Y', 'G', 'G', 'G', 'G', 'G', 'G', 'G' },
		{ 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'G', 'X', 'X', 'X' },
		{ 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'X', 'X', 'X' },
		{ 'W', 'W', 'W', 'W', 'W', 'G', 'G', 'G', 'G', 'X' },
		{ 'W', 'R', 'R', 'R', 'R', 'R', 'G', 'X', 'X', 'X' },
		{ 'W', 'W', 'W', 'R', 'R', 'G', 'G', 'X', 'X', 'X' },
		{ 'W', 'B', 'W', 'R', 'R', 'R', 'R', 'R', 'R', 'X' },
		{ 'W', 'B', 'B', 'B', 'B', 'R', 'R', 'X', 'X', 'X' },
		{ 'W', 'B', 'B', 'X', 'B', 'B', 'B', 'B', 'X', 'X' },
		{ 'W', 'B', 'B', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }
	};

	// start node 
	int x = 3, y = 9;	// having target color = "X"

	// replacement color
	char replacement = 'C';

	// replace target color with replacement color using DFS
	floodfill(mat, x, y, replacement);

	// print the colors after replacement
	for (int i = 0; i < M; i++) 
	{
		for (int j = 0; j < N; j++)
			cout << setw(3) << mat[i][j];
 
		cout << '\n';
	}
}
