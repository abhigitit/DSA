/*
Detect Cycles in 2D Grid Leetcode

*/

class Solution {
public:
    bool flag = false;
    vector<vector<int>> visited;
    bool containsCycle(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        visited.resize(rows,vector<int>(cols,0));
        for(int i=0;i<rows and flag==false;++i)
        {
            for(int j=0;j<cols;++j)
            {
                if(visited[i][j]==0)
                {
                     color(i,j,grid,0,grid[i][j]);
                }
                if(flag)
                    return true;
            }
        }
        
        return false;
    }
    
    void color(int i,int j,vector<vector<char>>& grid,int t,char c)
    {
        if(i<0 or j<0 or i>=visited.size() or j>=visited[i].size() or grid[i][j]!=c)
            return;
        
        if(visited[i][j]!=0)
        {
            if(t-visited[i][j]+1>=4)
                flag=true;
            return;
        }
        if(flag)
            return;
        
        t++;
        visited[i][j]=t;
        color(i,j+1,grid,t,c);
         color(i+1,j,grid,t,c);
         color(i,j-1,grid,t,c);
         color(i-1,j,grid,t,c);
    }
};
