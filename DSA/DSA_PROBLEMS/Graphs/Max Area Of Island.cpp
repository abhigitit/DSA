
/*
Leetcode: 695

Intution : 2D matrix DFS
Count 1s
TC : O(m*n)
SC: O(1) //not including recursive stack
*/

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        int count = 0;
        for(int i=0;i<grid.size();++i)   
        {
            for(int j=0;j<grid[i].size();++j)
            {
                if(grid[i][j]==1)
                {
                    DFS(i,j,grid,count);
                    max_area = max(max_area,count);
                    count = 0;
                }
            }
        }
        return max_area;
    }
    
    void DFS(int i,int j, vector<vector<int>>& grid,int &count)
    {
        if(i<0 or j<0 or i>=grid.size() or j>=grid[i].size() or grid[i][j]!=1)
            return;
        if(grid[i][j]==1) count++;
        grid[i][j]=0;
        DFS(i+1,j,grid,count);
        DFS(i-1,j,grid,count);
        DFS(i,j+1,grid,count);
        DFS(i,j-1,grid,count);
    }
};
