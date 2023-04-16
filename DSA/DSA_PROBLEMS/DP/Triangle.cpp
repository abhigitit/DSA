/*
Triangle

Variable destination. So start from 0,0. 
Own sol. refer takeuforward
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m,vector<int>(m,-1));
        return helper(0,0,triangle,m,dp);

    }

    int helper(int i,int j,vector<vector<int>>& triangle,int rows,vector<vector<int>>& dp)
    {
        if(i==rows-1)
        {
            return triangle[i][j];
        }

        if(dp[i][j]!=-1) return dp[i][j];
        int leftD = helper(i+1,j,triangle,rows,dp);
        int rightD = helper(i+1,j+1,triangle,rows,dp);

        int sum = triangle[i][j] + min(leftD,rightD);
        return dp[i][j]=sum;
    }
};
