/*
Find Peak Element

Go to middle element. If the element on the right of middle element is greater than mid element, then peak element lies in the right side.
Intuition is that if that right element to the mid is bigger the that could be the peak element, or the right one could be medium...
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;

        while(low<high)
        {
           int mid = low + (high-low)/2;
           if(nums[mid]<nums[mid+1])
           {
               low = mid+1;
           }
           else
            high = mid;
        }
        return high;
    }
};
