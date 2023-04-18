/*
0 1 Knapsack
*/
#include <bits/stdc++.h> 

int helper(int idx, int wt,vector<int> weight, vector<int> value,vector<vector<int>>& dp)
{

	if(idx==0)
	{
		if(weight[idx]<=wt) return value[idx];
		else return 0;
	}
	if(dp[idx][wt]!=-1) return dp[idx][wt];
	int notTake = helper(idx-1,wt,weight,value,dp);
	int take = INT_MIN;
	if(weight[idx]<=wt) 
		take = value[idx] + helper(idx-1,wt-weight[idx],weight,value,dp);
	
	return dp[idx][wt]=max(notTake,take);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n+1,vector<int>(maxWeight+1,-1));
	return helper(n-1,maxWeight, weight,value,dp);
}
