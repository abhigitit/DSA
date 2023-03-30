/*

Leetcode: 189

Intuition : Reverse whole, reverse in parts.

*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        reverse(nums.begin(),nums.end());
        
        reverse_func(0,k-1,nums);
        reverse_func(k,nums.size()-1,nums);
        
        
    }
    
    void reverse_func(int i,int j,vector<int>& nums)
    {
        while(i<j)
        {
            int temp = nums[j];
            nums[j] = nums[i];
            nums[i] = temp;
            i++;
            j--;
        }
    }
};
