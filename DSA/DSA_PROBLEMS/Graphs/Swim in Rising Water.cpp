/*

Swim in Rising Water

https://www.youtube.com/watch?v=amvrKlMLuGY&ab_channel=NeetCode

Intuition : Maximum elevation along the path should be minimum when compared to other paths' max.
1,2,2,1 ->choose this; as maximum elevation is 2 and at time 2, we can swim to destination
1,1,1,3

Maintain states in the queue where we compare current height and previous height and keep on updating maximum. 
Use priority_queue to pick the minimum height required until now path -> Being Greedy (Djikstras)

O(n^2logn)
All cells are pushed into min_heap.

*/

typedef vector<int> v;

struct comparator{
    bool operator()(v v1, v v2)
    {
        return v1[0]>v2[0];
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
      priority_queue<v,vector<v>,comparator> min_heap;
      vector<vector<bool>> visited(n,vector<bool>(n,false));
      min_heap.push({grid[0][0],0,0});
     vector<vector<int>> directions = {{1,0},{-1,0},{0,-1},{0,1}};
      while(!min_heap.empty())
      {
          v temp = min_heap.top();
          min_heap.pop();
          int curr_height = temp[0];
          int x = temp[1];
          int y = temp[2];
          
          if(x==n-1 and y==n-1)
              return curr_height;

          for(int i=0;i<directions.size();++i)
          {
              int new_x = x + directions[i][0];
              int new_y = y + directions[i][1];
              if(new_x<0 or new_y<0 or new_x>=n or new_y>=n or visited[new_x][new_y])
              continue;
              visited[x][y] = true;
              min_heap.push({max(curr_height,grid[new_x][new_y]),new_x,new_y});
          }
  
      }
        
        return -1;
      
    }
};
