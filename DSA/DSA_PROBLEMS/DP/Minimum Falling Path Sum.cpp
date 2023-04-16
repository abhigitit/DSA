/*
Minimum Falling Path Sum
*/
class Solution {
    int m;
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        m = matrix.size();
        int res = INT_MAX;
        vector<vector<int>>dp(m,vector<int>(m,-1));
        for(int j=0;j<m;++j)
        {
            res = min(res,helper(m-1,j,matrix,dp));
        }

        return res;
    }

    int helper(int i, int j,vector<vector<int>>& matrix,vector<vector<int>>&dp)
    {
        if(j<0 or j>=m) return 1e9;
        if(i==0) return matrix[i][j];
    
        if(dp[i][j]!=-1) return dp[i][j];
        int up = helper(i-1,j,matrix,dp);
        int leftD = helper(i-1,j-1,matrix,dp);
        int rightD = helper(i-1,j+1,matrix,dp);

        int sum = matrix[i][j] + min(up, min(leftD,rightD));

        return dp[i][j]=sum;
    }
};
