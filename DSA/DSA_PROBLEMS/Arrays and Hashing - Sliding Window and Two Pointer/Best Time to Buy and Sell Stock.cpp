/*
Best Time to Buy and Sell Stock

Kadane's algorithm

*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int profit = 0;
        int mini = prices[0];
        
        for(int i=1;i<prices.size();++i)
        {
            mini = min(mini,prices[i]);
            profit = max(profit,prices[i]-mini);
        }
        
        return profit;
    }
};
