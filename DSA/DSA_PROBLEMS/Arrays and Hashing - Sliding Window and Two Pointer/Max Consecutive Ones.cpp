/*
Max Consecutive Ones
 If curr==1, store new length, if curr== 0, move left pointer to right+1
 */
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = INT_MIN;
        int left = 0;
        int right = 0;
        int len = 0;
        while(right<nums.size()){
            if(nums[right]==1)
            {
                res = max(res,right-left+1);
            }

            if(nums[right]==0)
            {
                left = right+1; 
            }
            right++;

        }
        return res!=INT_MIN ? res : 0;
    }
};
