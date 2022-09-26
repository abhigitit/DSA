/*

 Best Time to Buy and Sell Stock II
 youtube.com/watch?v=3SJ3pUkPQMc&ab_channel=NeetCode
 
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==1) return 0;
        int left =0;
        int right =1;
        int profit=0;

        while(right<prices.size())
        {
     
            if(prices[right]>prices[left])
            {
                profit+=prices[right]-prices[left];
            }
            left++;
            right++;
                
        }
        return profit;
    }
};
