/*
Pacific Atlantic Water Flow

Intuition : 
change problem from cell to reach ocean => ocean to reach cell
Take two seperate 2D boolean grids one for pacific and atlantic each. Start from the boundary elements which are already into pacific and apply DFS
and mark all the elements that can flow into pacific. Similarly for atlantic.

Take common elements from both boolean grids.

*/

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> res;
        vector<vector<bool>> pacific(rows,vector<bool>(cols));
        vector<vector<bool>> atlantic(rows,vector<bool>(cols));
        
        for(int i=0;i<rows;++i)
        {
            dfs(i,0,pacific,heights);
            dfs(i,cols-1,atlantic,heights);
        }
        
         for(int j=0;j<cols;++j)
        {
            dfs(0,j,pacific,heights);
            dfs(rows-1,j,atlantic,heights);
        }
        
        for(int i=0;i<rows;++i)
        {
            for(int j=0;j<cols;++j)
            {
                if(pacific[i][j] and atlantic[i][j])
                    res.push_back({i,j});
            }
        }
        return res;
        
    }
    
    void dfs(int i, int j,vector<vector<bool>>& visited, vector<vector<int>>& heights)
    {
         int rows = heights.size();
        int cols = heights[0].size();
        visited[i][j] = true;
        
        if(i-1 >= 0 and !visited[i-1][j] and heights[i-1][j] >= heights[i][j])
            dfs(i-1,j,visited,heights);
        
        if(i+1 < rows and !visited[i+1][j] and heights[i+1][j] >= heights[i][j])
            dfs(i+1,j,visited,heights);
        
        if(j-1 >= 0 and !visited[i][j-1] and heights[i][j-1] >= heights[i][j])
            dfs(i,j-1,visited,heights);
        
        if(j+1 < cols and !visited[i][j+1] and heights[i][j+1] >= heights[i][j])
            dfs(i,j+1,visited,heights);
    }
};
