/* 
Leetcode : LIS

Intuition: LIS starting at the last index is always 1. 
***LIS at every index is 1 to start off with. Take a dp array with 1 at every index.

For every element, we check all the elements to the right, so will be using loop within loop.
and  if the current element is less than the right element, then we compute the LIS starting at that index LIS[i] = max(LIS[i], 1+LIS[j])

TC: O(n^2)
SC : O(n)

*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> LIS(nums.size(),1);
        
        for(int i=nums.size()-2;i>=0;--i)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]<nums[j])
                {
                    LIS[i] = max(LIS[i],1+LIS[j]);
                }
               
            }
        }
        
        return *max_element(LIS.begin(),LIS.end());
    }
};
