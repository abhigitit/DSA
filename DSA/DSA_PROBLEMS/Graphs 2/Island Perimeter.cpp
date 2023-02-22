/*

Island Perimeter

Intuition : If the edge is water or out of board boundary, return 1 and if the cell is already visited, thats not perimeter return 0.

*/

class Solution {
public:
int rows;
int cols;
set<int> visited;
    int islandPerimeter(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        for(int i=0;i<rows;++i)
            for(int j=0;j<cols;++j)
                if(grid[i][j]==1)
                    return dfs(i,j,grid);
        
        return 0;
    }

    int dfs(int i, int j, vector<vector<int>>& grid)
    {
        if(min(i,j)<0 or i>=rows or j>=cols or grid[i][j]!=1)
            return 1;
        if(visited.count(i*cols + j))
            return 0;
        
        visited.insert(i*cols + j);
        int perimeter = 0;
        perimeter+= dfs(i+1,j,grid) + dfs(i-1,j,grid) + dfs(i,j+1,grid) + dfs(i,j-1,grid); 

        return perimeter;


    }
}
----

class Solution {
public:
    int rows;
    int cols;
    vector<vector<bool>> visited;
    int islandPerimeter(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        visited.resize(rows,vector<bool>(cols,false));
        for(int i=0;i<rows;++i)
        {
            for(int j=0;j<cols;++j)
            {
                if(grid[i][j]==1)
                    return DFS(i,j,grid);
            }
        }
        
        return 0;
    }
    
    int DFS(int i,int j, vector<vector<int>>& grid)
    {
        if(i<0 or j<0 or i>=rows or j>=cols or grid[i][j]==0)
            return 1;
        if(visited[i][j])
            return 0;
        
        visited[i][j] = true;
        int p = 0; 
        p+= DFS(i+1,j,grid) + DFS(i-1,j,grid) + DFS(i,j+1,grid) + DFS(i,j-1,grid);
        return p;
    }
};
