/*
Leetcode: 34

*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int j =-1, k=-1;
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]==target)
            {
                if(k!=-1)
                {
                    j++;
                }
                else
                {
                k = i;
                j = i;  
                }
                
            }
        }
       if(k!=-1) return {k,j};
        else
            return {-1,-1};
    }
};
