/*

Frog Jump
start from last step
*/

#include <bits/stdc++.h> 
#include <cmath>

int min(int x,int y)
{
    return x<y ? x : y;
}
int helper(int n, vector<int> &heights,vector<int>& dp)
{
    if(n==0)
        return 0;
    if(dp[n]!=-1)
        return dp[n];
    int left = abs(heights[n]-heights[n-1]) + helper(n-1,heights,dp);
    int right = INT_MAX;
    if(n>1)
        right = abs(heights[n] - heights[n-2]) + helper(n-2,heights,dp);
    return dp[n] = min(left,right);
}
int frogJump(int n, vector<int> &heights)
{
vector<int> dp(n,-1);
return helper(n-1,heights,dp);
}
