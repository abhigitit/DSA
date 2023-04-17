/*
Counts Subsets with Sum K 
*/

#include <bits/stdc++.h> 

int helper(int idx, int target,vector<int> &num,vector<vector<int>>&dp)
{
    if(target==0) return 1;
    if(idx==0) return num[idx]==target;
    if(dp[idx][target]!=-1) return dp[idx][target];
    int notTake = helper(idx-1,target,num,dp);
    int take = 0;
    if(num[idx]<=target)
        take = helper(idx-1,target-num[idx],num,dp);
    return dp[idx][target] = notTake + take;
}
int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>>dp(n+1,vector<int>(tar+1,-1));
    return helper(n-1,tar,num,dp);
}
