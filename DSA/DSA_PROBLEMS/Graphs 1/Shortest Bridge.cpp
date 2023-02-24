/*
Shortest Bridge

Intuition : Shortest distance between 2 islands. To collect the 1s in a single island, we apply dfs. Then with those coordinates, we apply multi source, multi
destination BFS to reach second islands' 1's.
For shortest path with no weights = BFS

As soon as the dfs finds the first island and returns we need to call bfs and return the shortest dis

O(N*M)

*/


class Solution {

int rows;
int cols;
set<int> visited;
queue<pair<int,int>> q;

vector<vector<int>> directions;
   bool invalid(int i, int j,vector<vector<int>>& grid)
    {
        return (min(i,j)<0 or i>=rows or j>=cols or visited.count(i*cols + j));
        
    }

    void dfs(int i, int j, vector<vector<int>>& grid)
    {
        if(invalid(i,j,grid) or !grid[i][j])
            return;
        visited.insert(i*cols + j);
        q.push({i,j});
        dfs(i+1,j, grid);
        dfs(i-1,j, grid);
        dfs(i,j+1, grid);
        dfs(i,j-1, grid);
        

    }

    int bfs(vector<vector<int>>& grid)
    {
        int res = 0;
        while(!q.empty())
        {
            int s = q.size();
            for(int i=0;i<s;++i)
            {
                auto temp = q.front();
                q.pop();
                int x = temp.first;
                int y = temp.second;

                for(int k=0;k<directions.size();++k)
                {
                    int dx = x + directions[k][0];
                    int dy = y + directions[k][1];

                    if(invalid(dx,dy,grid))
                        continue;
                    if(grid[dx][dy])
                        return res;
                    q.push({dx,dy});
                    visited.insert(dx*cols + dy);
                }
            }
            res++;
        }
        return -1;

    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        directions = {{1,0},{-1,0},{0,1},{0,-1}};
        
        for(int i=0;i<rows;++i)
        {
            for(int j=0;j<cols;++j)
            {
                if(grid[i][j])
                {
                    dfs(i,j,grid);
                    
                    return bfs(grid);
                }
            }
        }
        return 0;
    }
   
};
