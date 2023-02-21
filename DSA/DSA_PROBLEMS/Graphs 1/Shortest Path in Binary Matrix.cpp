/*

Matriix BFS
Shortest path from top left to bottom right


Shortest Path in Binary Matrix
1091

8 directions move. BFS = shortest path

TC : O(n*m)
*/
Incrementing len after each layer exploration
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int len = 1;
        if(grid[0][0]==1) return -1;
        queue<pair<int,int>> bfs;
        set<pair<int,int>> visited;
        visited.insert({0,0});
        int rows = grid.size();
        int cols = grid[0].size();
        
        bfs.push({0,0});
        vector<vector<int>> directions = {{1,0},{-1,0},{0,-1},{0,1},{1,1},{-1,1},{1,-1},{-1,-1}};
        
        while(!bfs.empty())
        {
            int s = bfs.size();
            for(int i=0;i<s;++i)
            {
               pair<int,int> temp = bfs.front();
               bfs.pop();
            
            int x = temp.first;
            int y = temp.second;

            if(x==rows-1 and y==cols-1)
                return len;
            for(int j=0;j<directions.size();++j)
            {
                int new_x = x + directions[j][0];
                int new_y = y + directions[j][1];

                if(min(new_x,new_y) < 0 or new_x == rows or new_y == cols or visited.count({new_x,new_y}) or grid[new_x][new_y]==1)
                {
                    continue;
                }
                    
                  bfs.push({new_x,new_y});
                  visited.insert({new_x,new_y});
                
            } 
            }
            
            
            len++;
        }      
        return -1;
    }
};

_____
   Incrementing len with every node with value 0
  
  class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        if(grid[0][0]==1) return -1;
        queue<vector<int>> bfs;
        set<pair<int,int>> visited;
        visited.insert({0,0});
        int rows = grid.size();
        int cols = grid[0].size();
        
        bfs.push({0,0,1});
        vector<vector<int>> directions = {{1,0},{-1,0},{0,-1},{0,1},{1,1},{-1,1},{1,-1},{-1,-1}};
        
        while(!bfs.empty())
        {
            
               auto temp = bfs.front();
               bfs.pop();
            
            int x = temp[0];
            int y = temp[1];
            int len = temp[2];

            if(x==rows-1 and y==cols-1)
                return len;
            for(int j=0;j<directions.size();++j)
            {
                int new_x = x + directions[j][0];
                int new_y = y + directions[j][1];

                if(min(new_x,new_y) < 0 or new_x == rows or new_y == cols or visited.count({new_x,new_y}) or grid[new_x][new_y]==1)
                {
                    continue;
                }
                    
                  bfs.push({new_x,new_y,len+1});
                  visited.insert({new_x,new_y});
                
            } 
  
        }      
        return -1;
    }
};
