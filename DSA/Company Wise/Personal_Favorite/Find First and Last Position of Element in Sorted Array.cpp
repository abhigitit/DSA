
/*

Find First and Last Position of Element in Sorted Array

Intuition : Two seperate functions to squeeze towards first and last occurrences
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       vector<int> res(2,-1);
       res[0] = findFirst(0,nums.size()-1, nums, target);
       res[1] = findLast(0,nums.size()-1, nums, target) ;
       return res;
    }

    int findFirst(int left, int right,vector<int>& nums, int target)
    {
        int idx=-1;
        while(left<=right)
        {
            int mid = left + (right-left)/2;

        if(nums[mid]>=target) 
            right = mid-1;
        else
            left = mid+1;
        
        if(nums[mid]==target)
            idx = mid;
        }
       
        return idx;
    }

      int findLast(int left, int right,vector<int>& nums, int target)
    {
        int idx=-1;
        while(left<=right)
        {
            int mid = left + (right-left)/2;

        if(nums[mid]<=target) 
            left = mid+1;
        else
            right = mid-1;
        
        if(nums[mid]==target)
            idx = mid;
        }
       
        return idx;
    }
};
