/*
Search in Rotated Sorted Array

Intuition: There are 2 sorted parts in roated sorted array. Find the minimum element to seperate two sorted parts and find in which sorted part the target lies.
Then apply binary search

*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
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
        int start = left;
        left = 0;
        right = nums.size() - 1;
        
        
            if(target>=nums[start] && target<=nums[right]) 
                left = start;
        else
            right = start;
        
      while(left<=right)
        {
            int midpoint = left + (right-left)/2;
          if(nums[midpoint]==target)
              return midpoint;
            else if(nums[midpoint]<target)
                left = midpoint + 1;
            else
                right = midpoint-1;
        }
       
       return -1;
        
    }       
    
};
