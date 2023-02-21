/*
Shortest Path to Get Food

BFS
*/

class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        queue<vector<int>> que;
        set<pair<int,int>> visited;
        
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<vector<int>> directions = {{-1,0},{1,0},{0,1},{0,-1}};
        for(int i=0;i<rows;++i)
        {
            for(int j=0;j<cols;++j)
            {
                if(grid[i][j]=='*')
                {
                    que.push({i,j,0});
                    visited.insert({i,j});
                }
                    
            }
        }
        
        while(!que.empty())
        {
            auto temp = que.front();
            que.pop();
            
            int steps = temp[2];
            int x = temp[0];
            int y = temp[1];
            
            if(grid[x][y]=='#')
                return steps;
            
            for(int i=0;i<directions.size();++i)
            {
                int dx = x + directions[i][0];
                int dy = y + directions[i][1];
                
                if(min(dx,dy)<0 or dx>=rows or dy>=cols or visited.count({dx,dy}) or grid[dx][dy]=='X')
                    continue;
                
                
                que.push({dx,dy,steps+1});
                visited.insert({dx,dy});
                
                
            }
            
        }
        return -1;
    }
};


______

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
