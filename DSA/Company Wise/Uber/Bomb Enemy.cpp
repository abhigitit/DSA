/*
https://www.youtube.com/watch?v=jVSTaWLE3Ic
stateful column buffer that counts the enemies in column and row_enemy that counts enemies in current row. Two traversals top to bottom
and vice versa
*/

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
       const int rows = grid.size();
       const int cols = grid[0].size();
        vector<vector<int>> buffer(rows, vector<int>(cols,0));
        vector<int> col_enemy(cols,0);
        vector<int> col_enemy_2(cols,0);
        int ans = INT_MIN;
        for(int i=0;i<rows;++i) {
            int row_enemy = 0;
            for(int j=0;j<cols;++j) {
               
                if(grid[i][j]=='0')
                {
                    buffer[i][j]=row_enemy + col_enemy[j];
                }
                 else if(grid[i][j]=='E')
                {
                    col_enemy[j]++;
                    row_enemy++;
                    
                }
                
                else
                {
                     row_enemy=0;
                     col_enemy[j]=0;
                }
            }
        }
        
         for(int i=rows-1;i>=0;--i) {
            int row_enemy = 0;
            for(int j=cols-1;j>=0;--j) {
                
                 if(grid[i][j]=='0')
                {
                    buffer[i][j]+=row_enemy + col_enemy_2[j];
                    ans = max(ans, buffer[i][j]);
                }
                else if(grid[i][j]=='E')
                {
                    col_enemy_2[j]++;
                    row_enemy++;
                    
                }
                
               else
                {
                     row_enemy=0;
                     col_enemy[j]=0;
                }
            }
        }
        return ans!=INT_MIN?ans:0;
    }
};
