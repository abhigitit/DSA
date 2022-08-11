/* 
Leetcode 1293

The claim for BFS is that the first time a node is discovered during the traversal, that distance from the source would give us the shortest path.

Shortest path from first cell to last cell in a binary matrix without obstacles is always length of row+ length of column(the Manhattan distance) as we cant go diagonally. 

First edge case: 
If the no of obstacles to be broken >= length of row+ length of column
We can break all of them and take the path.


Use a queue which keeps track of number of steps take, current position, number of obstacles which could be broken
Use a map or set to store already seen cell in the grid.

TC: O(M*N)
SC : O(M*N)

*/

class Solution {
public:
    
    int shortestPath(vector<vector<int>>& grid, int k) {
    queue<pair<int,vector<int>>> helper;
    unordered_set<string> seen;
      int rows = grid.size();
      int cols = grid[0].size();
        
     vector<int> target(2);
        target = {rows-1,cols-1};
        if(k>=rows-1+cols-1)
            return (rows+cols-2);
  
       string first_entry = to_string(0) + ',' + to_string(0) + ',' + to_string(k);
        seen.insert(first_entry);
        vector<vector<int>> directions(4,vector<int>(2));
        directions = {{1,0},{-1,0},{0,1},{0,-1}};
        helper.push({0,{0,0,k}});
        while(!helper.empty())
        {
            pair<int,vector<int>> temp = helper.front();
            helper.pop();
            
            int steps = temp.first;
            vector<int> grab = temp.second;
            
            if(grab[0]==target[0] and grab[1]==target[1])
                return steps;
            
            for(int i=0;i<directions.size();++i)
            {
              
                int row_inc = directions[i][0];
                int col_inc = directions[i][1];
                int new_row = grab[0]+row_inc;
                int new_col = grab[1]+col_inc;

                if((0<=new_row<rows) and (0<=new_col<cols))
                {
                    int new_removal = grab[2]-grid[new_row][new_col];
                    string new_state = to_string(new_row) + ',' + to_string(new_col) + ',' + to_string(new_removal);
                    
                    if(new_removal>=0 and seen.find(new_state)==seen.end())
                    {
                        seen.insert(new_state);
                        helper.push({steps+1,{new_row,new_col,new_removal}});
                    }
                }
            }
            
        }
        
       return -1; 
    }
};
