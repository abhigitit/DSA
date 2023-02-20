/*
Rotting Oranges

Intuition : BFS

We need to process the rottening of oranges parallely i.e all the 2s in the matrix simultaneously rotten the adjacent 1s.
Hence, we will be performing multi source BFS.

Initially, we need to keep count of the fresh oranages and when the queue becomes empty, we need to check if the number of fresh oranges = 0 or >0
-When the queue becomes empty or fresh oranges become 0, we stop the BFS.
-Store the coordinates of rotten oranges in the queue.
-We need to pop all the rotten oranges --- a for loop 

*/
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> BFS;
        int fresh=0;
        int time=0;
        
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<vector<int>> directions = {{1,0},{-1,0},{0,-1},{0,1}};
        for(int i=0;i<rows;++i)
        {
            for(int j=0;j<cols;++j)
            {
                if(grid[i][j]==1)
                    fresh++;
                if(grid[i][j]==2)
                    BFS.push({i,j});
            }
        }
    
        while(!BFS.empty() and fresh>0)
        {
            int n = BFS.size();
            for(int i=0;i<n;++i)
            {
               pair<int,int> temp = BFS.front();
                BFS.pop();
                int x = temp.first;
                int y = temp.second;
                for(int i=0;i<directions.size();++i)
                {
                    int new_x = x + directions[i][0];
                    int new_y = y + directions[i][1];
                    if(new_x<0 or new_y<0 or new_x >=rows or new_y >=cols or grid[new_x][new_y]!=1)
                    continue;
                     grid[new_x][new_y]=2;
                    BFS.push({new_x,new_y});
                    fresh--; 
                }
            }
            time++;
        }
        return fresh==0 ? time : -1;
    }
};
