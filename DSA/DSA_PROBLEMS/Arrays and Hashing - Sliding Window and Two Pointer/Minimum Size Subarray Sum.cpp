/*
Minimum Size Subarray Sum
*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int running_sum = 0;
        int len = INT_MAX;
        int left = 0;
        int right = 0;

        while(right<nums.size())
        {
            running_sum+=nums[right];                
            while(running_sum>=target)
            {
                len = min(len,right-left+1);
                running_sum = running_sum-nums[left];
                left++;
            }
            right++;
        }
        return len!=INT_MAX ? len : 0;
    }
};
