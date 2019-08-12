#include <bits/stdc++.h>

using namespace std;

// Complete the quickestWayUp function below.
class Node
{
    public:
        int x, y, dist;
};

int quickestWayUp(vector<vector<int>> ladders, vector<vector<int>> snakes) {
    int **layout;
    int row = 100;
    int col = 100;
    
    layout = new int*[row];
    
    for(int i=1; i<=row; i++)
        layout[i] = new int[col];
    
    for(int i=1; i<=row; i++)
        for(int j=1; j<=col; j++)
            layout[i][j] = 0;
    

    unordered_map<int,int> mysnake, myladder;

    for(int i=0; i<snakes.size(); i++)
        mysnake[snakes[i][0]] = snakes[i][1];
    
    for(int i=0; i<ladders.size(); i++)
        myladder[ladders[i][0]] = ladders[i][1];

    for(int i=1; i<=row; i++)
    {    
        for(int j =1; j<=6 && i+j<=row ; j++)
        {
            if(myladder[i+j])
                layout[i][myladder[i+j]]=1;
            else if(mysnake[i+j])
                layout[i][mysnake[i+j]]=1;
            else    
                layout[i][i+j] = 1;
        }
    }
    
    bool **visited;
    visited = new bool*[row];
    
    for(int i=1; i<=row; i++)
        visited[i] = new bool[col];
    
    for(int i=1; i<=row; i++)
        for(int j=1; j<=col; j++)
            visited[i][j] = false;
            
    
    queue<Node> que;
    Node node = {1,1,0};
    que.push(node);
    
    while(!que.empty())
    {
        Node nd = que.front();
        int x = nd.x;
        int y = nd.y;
        int dist = nd.dist;
        
        que.pop();
        
        for(int j=y+1; j<=col ; j++)
        {
            if(layout[x][j] && !visited[x][j])
            {
                visited[x][j] = true;
                nd = {x,j,dist+1};
                que.push(nd);
                if(j==col && layout[x][j]==1)
                    return (dist+1);        
            }
        }
        
    }
    return 0;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> ladders(n);
        for (int i = 0; i < n; i++) {
            ladders[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> ladders[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int m;
        cin >> m;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> snakes(m);
        for (int i = 0; i < m; i++) {
            snakes[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> snakes[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int result = quickestWayUp(ladders, snakes);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

