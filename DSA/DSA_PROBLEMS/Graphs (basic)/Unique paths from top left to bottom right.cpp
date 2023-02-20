
/*
Unique paths from top left to bottom right. Can move along 0's

*/


#include<bits/stdc++.h>
using namespace std;

class Graph{
    vector<vector<int>> grid;
    int rows;
    int cols;
    set<pair<int,int>> visited;
    public:
    Graph(vector<vector<int>>& grid)
    {
       this->grid = grid; 
       rows = grid.size();
       cols = grid[0].size();
    }
    
    int unique_paths(int r, int c)
    {
        if(min(r,c)<0 or r==rows or c==cols or visited.count({r,c}) or grid[r][c]==1)
            return 0;
        
        if(r==rows-1 and c==cols-1)
            return 1;
        
        visited.insert({r,c});
        
        int count = 0;
        count+= unique_paths(r+1,c);
        count+= unique_paths(r,c+1);
        count+= unique_paths(r-1,c);
        count+= unique_paths(r,c-1);
        
        visited.erase({r,c});
        
        return count;
    }
    
};



int main()
{
    vector<vector<int>> grid = {{0,0,0,0},{1,0,0,0},{0,0,0,1},{0,1,0,0}};
    Graph g(grid);
    int res = g.unique_paths(0,0);
    cout<<res;
    return 0;
}
