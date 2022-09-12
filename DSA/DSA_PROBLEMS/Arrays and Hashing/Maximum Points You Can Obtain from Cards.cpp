
/*
Leetcode: 1423

Intuition : Sliding Window
https://www.youtube.com/watch?v=TsA4vbtfCvo&ab_channel=NeetCode
TC: O(k)
*/
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int left = 0;
        int right = cardPoints.size()-k;
        int total = 0;
        
        for(int i=right;i<cardPoints.size();++i)
        {
           total+= cardPoints[i];
        }
        cout<<total;
        int res = total;
        
        while(right<cardPoints.size())
        {
            total += cardPoints[left] - cardPoints[right];
            res = max(res,total);
            left++;
            right++;
        }
        
        return res;
    }
};
