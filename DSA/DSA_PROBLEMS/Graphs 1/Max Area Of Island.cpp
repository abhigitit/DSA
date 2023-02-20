
/*
Leetcode: 695

Intution : 2D matrix DFS
Count 1s
TC : O(m*n)
SC: O(1) //not including recursive stack
*/

class Solution {
public:
int rows;
int cols;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int area = 0, temp = 0;
        for(int i=0;i<rows;++i)
        {
            for(int j=0;j<cols;++j)
            {
                if(grid[i][j]==1)
                {
                    temp=0;
                    dfs(i,j,grid,temp);
                    area = max(area,temp);
                }
            }
        }

        return area;
    }

    void dfs(int i, int j,vector<vector<int>>& grid, int &temp)
    {
        if(min(i,j)<0 or i>=rows or j>=cols or grid[i][j]!=1)
            return;
        
        temp++;
        grid[i][j]=0;
        dfs(i+1,j,grid,temp);
        dfs(i-1,j,grid,temp);
        dfs(i,j+1,grid,temp);
        dfs(i,j-1,grid,temp);
    }
};
