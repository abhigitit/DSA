/*
Code Ninja
Ninja Training
https://www.youtube.com/watch?v=AE39gJYuRog&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=8
*/

#include<bits/stdc++.h>
int helper(int day,int last,vector<vector<int>> &points,vector<vector<int>>& dp)
{
    if(day==0)
    {
        int maxi = 0;
        for(int i=0;i<3;++i)
        {
            
            if(i!=last)
            {
                maxi = max(maxi,points[0][i]);
            }
        }
        return maxi;
    }
    if(dp[day][last]!=-1) return dp[day][last];
    int maxe = 0;
    for(int i=0;i<3;++i)
    {
        if(i!=last)
        {
        int today_points = 0;
        today_points = points[day][i] + helper(day-1,i,points,dp);
        maxe = max(maxe,today_points);
        }
       
    }
    return dp[day][last]=maxe;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n,vector<int>(4,-1));
    return helper(n-1,3,points,dp);
}
