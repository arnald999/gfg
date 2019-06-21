#include <iostream>
#include <queue>
#define R 3 
#define C 5
using namespace std;

class Rotten
{
	public:	
		int x,y;
};

bool isvalid(int i, int j) 
{ 
    return (i >= 0 && j >= 0 && i < R && j < C); 
}

bool isdelim(Rotten temp) 
{ 
    return (temp.x == -1 && temp.y == -1); 
}

bool checkall(int arr[][C]) 
{ 
    for (int i=0; i<R; i++) 
       for (int j=0; j<C; j++) 
          if (arr[i][j] == 1) 
             return true; 
    return false; 
}

int allrotten(int arr[][C])
{
	queue<Rotten> q;
	Rotten temp;
	
	int res = 0;
	
	for(int i=0; i<R; i++)
	{
		for(int j = 0; j<C; j++)
		{
			if(arr[i][j]==2)
			{
				temp.x = i;
				temp.y = j;
				q.push(temp);
			}
		}
	}
	
	
	
	temp.x = -1;
	temp.y = -1;
	q.push(temp);
	
	while(!q.empty())
	{
		bool flag = false;
		
		while(!isdelim(q.front()))
		{
			temp = q.front();
			if(isvalid(temp.x+1, temp.y) && arr[temp.x+1][temp.y]==1)
			{
				if (!flag) res++, flag = true;
				arr[temp.x+1][temp.y] = 2;
				
				temp.x++; 
                		q.push(temp);
                		
                		temp.x--;
			}
			
			if(isvalid(temp.x-1, temp.y) && arr[temp.x-1][temp.y]==1)
			{
				if (!flag) res++, flag = true;
				arr[temp.x-1][temp.y] = 2;
				
				temp.x--; 
                		q.push(temp);
                		
                		temp.x++;
			}
			
			if(isvalid(temp.x, temp.y+1) && arr[temp.x][temp.y+1]==1)
			{
				if (!flag) res++, flag = true;
				arr[temp.x][temp.y+1] = 2;
				
				temp.y++; 
                		q.push(temp);
                		
                		temp.y--;
			}
			
			if(isvalid(temp.x, temp.y-1) && arr[temp.x][temp.y-1]==1)
			{
				if (!flag) res++, flag = true;
				arr[temp.x][temp.y-1] = 2;
				
				temp.y--; 
                		q.push(temp);
                		
                		temp.y++;
			}
			
			q.pop();
		}
		
		//pop delimiter
		q.pop();
		
		if (!q.empty()) 
		{ 
			temp.x = -1; 
			temp.y = -1; 
			q.push(temp); 
        	} 
	}
	return (checkall(arr))? -1: res;
}

int main() 
{ 
	int arr[][C] = { {2, 1, 0, 2, 1}, 
		     {1, 0, 1, 2, 1}, 
		     {1, 0, 0, 2, 1}}; 
	int res = allrotten(arr); 
	if (res == -1) 
		cout << "All oranges cannot rotn"; 
	else
	 	cout << "Time required for all oranges to rot => " << res << endl; 
	return 0; 
} 
