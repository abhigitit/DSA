/*
First Missing Positive
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]<=0)
                nums[i]=nums.size()+1;
        }
         for(int i=0;i<nums.size();++i)
        {
             if(nums[i]==nums.size()+1) continue;
             int index = abs(nums[i])-1;
             if(index<nums.size())
                 nums[index]=-abs(nums[index]);
        }
        
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]>0)
                return i+1;
        }
        
        return nums.size()+1;
    }
};
