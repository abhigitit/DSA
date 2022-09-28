/*
Find Peak Element

Go to middle element. If the element on the right of middle element is greater than mid element, then peak element lies in the right side.
Intuition is that if that right element to the mid is bigger the that could be the peak element, or the right one could be medium...
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left =0;
        int n=nums.size();
        int right =n-1;
        int ans=0;
        if(nums.size()==1) return 0;
        if(nums.size()==2) return nums[0]>nums[1]?0:1;
        while(left<=right)
        {
            int mid = (left + right)/2;
            if(mid-1>=0 and nums[mid-1]>nums[mid])
                right = mid-1;
            else if(mid+1<nums.size() and nums[mid+1]>=nums[mid])
                left = mid+1;
            else
                 {
                ans = mid;
                break;
            }
        }
        return ans;
    }
};
