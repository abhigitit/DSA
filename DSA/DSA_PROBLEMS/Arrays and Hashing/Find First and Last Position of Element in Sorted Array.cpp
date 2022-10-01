/*
Leetcode: 34
Nick White
*/



class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> res(2,-1);
        res[0] = findFirst(0,nums.size()-1,nums,target);
        res[1] = findSecond(0,nums.size()-1,nums,target);
        return res;
    }
    
    int findFirst(int left, int right,vector<int>& nums, int target)
    {
        int idx = -1;
        
        while(left<=right)
        {
            int mid = left + (right-left)/2;
            
            if(nums[mid]>=target)
                right=mid-1;
            else
                left=mid+1;
            
            if(nums[mid]==target)
                idx = mid;
        }
        
        
        return idx;
    }
    
    int findSecond(int left, int right,vector<int>& nums, int target)
    {
        int idx =-1;
        
         while(left<=right)
        {
         int mid = left + (right-left)/2;
            
            if(nums[mid]<=target)
                left=mid+1;
            else
                right=mid-1;
            
            if(nums[mid]==target)
                idx = mid;
         }
        return idx;
    }
};


Brute force
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
