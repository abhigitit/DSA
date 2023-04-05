/*
Number of distinct islands
Save the shape of the island in set
*/


class Solution {
private:
    void dfs(int i,int j, vector<vector<int>>& grid,vector<pair<int,int>> shape, int xo,int yo)
    {
        if(min(i,j)<0 or i==rows or j==cols or visited[i][j] or grid[i][j]!=1)
            return;
        visited[i][j] = 1;
        shape.push_back({i-xo,j-yo});
        
        dfs(i+1,j,grid,shape,xo,yo);
        dfs(i-1,j,grid,shape,xo,yo);
        dfs(i,j+1,grid,shape,xo,yo);
        dfs(i,j-1,grid,shape,xo,yo);
    }
public:
    set<vector<pair<int,int>>> res;
    vector<vector<int>> visited;
    int rows;
    int cols;
    int numDistinctIslands(vector<vector<int>>& grid) {
         rows = grid.size();
         cols = grid[0].size();
        visited.resize(rows, vector<int>(cols,0));
        
        for(int i=0;i<rows;++i)
        {
            for(int j=0;j<cols;++j)
            {
                if(!visited[i][j] and grid[i][j]==1)
                {
                    vector<pair<int,int>> shape;
                    dfs(i,j,grid,shape,i,j);
                    res.insert(shape);
                }
            }
        }
        
        
        return res.size();
    }
};
