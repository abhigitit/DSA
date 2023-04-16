/*
Unique Paths II

Just one more condition
*/
class Solution {

    int helper(int i,int j,vector<vector<int>>& obstacleGrid,vector<vector<int>>&dp)
    {
        if(i==0 and j==0) return 1;
        if(i<0 or j<0 or(obstacleGrid[i][j]==1)) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int left = helper(i,j-1,obstacleGrid,dp);
        int up = helper(i-1,j,obstacleGrid,dp);

        return dp[i][j]=left+up;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        if(obstacleGrid[0][0]==1 or obstacleGrid[m-1][n-1]==1) return 0;
        if(m==1 or n==1) return 1;
        return helper(m-1,n-1,obstacleGrid,dp);
    }
};
