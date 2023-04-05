/*
Walls and Gates*/


class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<vector<int>> gates;
        int rows = rooms.size();
        int cols = rooms[0].size();
        int empty = 0;
        vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
        for(int i=0;i<rows;++i)
        {
            for(int j=0;j<cols;++j)
            {
                if(rooms[i][j]==0)
                      gates.push({i,j,0});
            }
        }
        
        while(!gates.empty())
        {
            int size = gates.size();
            for(int i=0;i<size;++i)
            {
                auto temp = gates.front();
                gates.pop();
                int x = temp[0];
                int y = temp[1];
                int distance = temp[2];
                
       
                for(int i=0;i<directions.size();++i)
                {
                    int new_x = x+directions[i][0];
                    int new_y = y+directions[i][1];
                    
                    if(min(new_x,new_y)<0 or new_x==rows or new_y==cols or rooms[new_x][new_y]!=INT_MAX)
                        continue;
                    rooms[new_x][new_y] = distance+1;
                    gates.push({new_x,new_y,distance+1});
                }
                
            }
        }
    }
};
