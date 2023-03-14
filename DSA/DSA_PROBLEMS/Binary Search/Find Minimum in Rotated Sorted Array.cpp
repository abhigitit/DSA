/*
 Find Minimum in Rotated Sorted Array
 Intuition: The element which is lesser than the previous one is the minimum. O(N)
 To do in logN, eliminate the side that is sorted.
 */

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while(left<right)
        {
            int midpoint = left + (right-left)/2;
            if(nums[midpoint]>nums[right])
                left = midpoint + 1;
            else
                right = midpoint;
        }
        return nums[left];

    }
};
