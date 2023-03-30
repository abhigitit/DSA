/*
Max Consecutive Ones III

Can change one 0 to 1. So if the count of 0’s exceeds 1, we shrink from the left side to remove all 1’s from the 
current window because the window is only broken due to extra 0’s. 
Now while shrinking, if we come across 0’s we update count of 0’s

*/
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
         int left = 0;
        int right = 0;
        int res = INT_MIN;
        int count = 0;
        while(right<nums.size())
        {
            if(nums[right]==0)
                   count++;
           
            while(count>k)
            {
                if(nums[left]==0)
                    count--;
                left++;
            }
            res = max(res,right-left+1);
            right++;
          
        }
        return res!=INT_MIN ? res : 1;
    }
};
