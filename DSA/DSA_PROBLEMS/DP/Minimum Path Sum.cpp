/*
Minimum Path Sum
own

base case
do stuff
blindly trust recursion; recursive leap of faith
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return helper(m-1,n-1,grid,dp);
    }

    int helper(int i,int j, vector<vector<int>>& grid, vector<vector<int>>& dp)
    {
        if(i==0 and j==0)
        {
            return grid[i][j];
        }

        if(i<0 or j<0)
            return 1e9;
        
        if(dp[i][j]!=-1) return dp[i][j];
        int left = helper(i,j-1,grid,dp);
        int up = helper(i-1,j,grid,dp);

        int sum = grid[i][j] + min(left,up);

        return dp[i][j] = sum;
    }
};
