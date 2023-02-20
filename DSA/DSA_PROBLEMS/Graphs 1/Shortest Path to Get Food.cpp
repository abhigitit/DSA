/*
Shortest Path to Get Food

BFS
*/

class Solution {
public:
    int getFood(vector<vector<char>>& grid) {

        queue<vector<int>> BFS;
        for(int i=0;i<grid.size();++i)
        {
            for(int j=0;j<grid[i].size();++j)
            {
                if(grid[i][j]=='*')
                {
                   BFS.push({i,j,0});
                }
                    
            }
        }
        while(!BFS.empty())
        {
           
        vector<int> temp= BFS.front();
            BFS.pop();
            int x = temp[0];
            int y = temp[1];
            int steps = temp[2];
            
            if(x<0 or y<0 or x>=grid.size() or y>=grid[0].size() or grid[x][y]=='X')
                continue;
            
            if(grid[x][y]=='#')
                return steps;
            
            
            grid[x][y] = 'X';
            
            BFS.push({x+1,y,steps+1});
            BFS.push({x-1,y,steps+1});
            BFS.push({x,y+1,steps+1});
            BFS.push({x,y-1,steps+1});
        }
        return -1;
    }
};
