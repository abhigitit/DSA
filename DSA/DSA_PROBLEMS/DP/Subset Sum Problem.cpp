/*
TakeUF
*/
class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n= arr.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return helper(n-1,sum,arr,dp);
    }
    
    bool helper(int idx, int target,vector<int>&arr,vector<vector<int>>&dp)
    {
        if(target==0) return true;
        if(idx==0) return arr[idx]==target;
        if(dp[idx][target]!=-1) return dp[idx][target];
        bool notTake = helper(idx-1,target,arr,dp);
        bool take = false;
        if(arr[idx]<=target)
            take = helper(idx-1,target-arr[idx],arr,dp);
        
        return dp[idx][target] = notTake or take;
    }
};
