/*
Number of Islands
*/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int res=0;
        for(int i=0;i<rows;++i)
        {
            for(int j=0;j<cols;++j)
            {
                if(grid[i][j]=='1')
                {
                    DFS(i,j,grid);
                    res++;
                }
            }
        }
        
        return res;
    }
    
    void DFS(int i,int j, vector<vector<char>>& grid)
    {
        if(i<0 or j<0 or i>=grid.size() or j>=grid[i].size() or grid[i][j]!='1')
            return;
        
        grid[i][j]='0';
        DFS(i+1,j,grid);
        DFS(i-1,j,grid);
        DFS(i,j+1,grid);
        DFS(i,j-1,grid);
  
    }
};
