/*

1905 Count Sub Islands

*/

class Solution {
public:
int rows;
int cols;
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ans = 0;
        rows = grid2.size();
        cols = grid2[0].size();
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid2[i][j] == 1 && grid2[i][j] == grid1[i][j]){
                    int flag = 1;
                    dfs(grid1, grid2, i, j, flag);
                    ans += flag;
                }
            }
        }
        
        return ans;
    }
    
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, int &flag){
          if(min(i,j)<0 or i>=rows or j>=cols or grid2[i][j]!=1)
                return;

          grid2[i][j]=2;
          if(grid1[i][j]==0)
                flag = 0;
            
            dfs(grid1, grid2, i+1, j, flag);
            dfs(grid1, grid2, i-1, j, flag);
            dfs(grid1, grid2, i, j+1, flag);
            dfs(grid1, grid2, i, j-1, flag);
        }
    
};
