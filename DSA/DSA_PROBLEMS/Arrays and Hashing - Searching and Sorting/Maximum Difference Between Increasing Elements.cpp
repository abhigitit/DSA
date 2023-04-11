/*
Maximum Difference Between Increasing Elements
*/

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxe = nums[nums.size()-1];
        int res = INT_MIN;
        for(int i=nums.size()-2;i>=0;--i)
        {
            if(nums[i]<maxe)
            {
                res = max(res,maxe-nums[i]);
            }

            maxe = max(nums[i],maxe);

        }
        return res!=INT_MIN ? res : -1;
    }
};
