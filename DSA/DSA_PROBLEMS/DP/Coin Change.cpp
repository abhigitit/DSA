/*
Leetcode: Coin Change

Intuition:
Iterate through the denominations and check how many minimum denoms are required to make $0 to $n

Denom should be less than or equal to the dollar(change) we are trying to make.

Let the denom be $1
How many dollars to make 0 = 0 1<=0?  No.. so we cannot make 0 with $1s
How many dollars to make 1 => 1<=1? Yes, then 1-1(used one here) = 0(check how many required for 0)

How many dollars to make 2 => 1<=2? Yes, then 2-1(used one here) = 1(check how many required for 1) its 1+1

How many dollars to make 3 => 1<=3? Yes, then 3-1(used one here) = 2(check how many required for 2) its 1+2


Let the denom be 2
How many dollars to make 0 = 0 2<=0?  No.. so we cannot make 0 with $2s
How many dollars to make 1 => 2<=1?  No.. so we cannot make 1 with $2s


How many dollars to make 2 => 2<=2?  Yes, then 2-2(used one here) = 0(check how many required for 0) Its 1. Now this 1 is less than previously stored value to make $2 change(2). Change this in the dp array.

*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,INT_MAX);
        dp[0]=0;
        
        for(auto i:coins)
        {
            for(int j=0;j<dp.size();++j)
            {
                if(i<=j)
                {
                    if(dp[j-i]==INT_MAX)
                    dp[j]=min(dp[j],dp[j-i]);
                    else
                       dp[j]=min(dp[j],1+dp[j-i]); 
                }
            }
        }
        return dp[amount]!=INT_MAX ? dp[amount] : -1;
    }
};
