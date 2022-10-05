/*
Squares of a Sorted Array

*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size(),0);
        int left = 0;
        int right = nums.size()-1;
        for(int i=nums.size()-1;i>=0;--i)
        {
            int small = nums[left];
            int big = nums[right];
            if(abs(small)>abs(big))
            {
                res[i]=small*small;
                left++;
            }
            else
            {
                res[i] = big*big;
                right--;
            }
        }
        return res;
    }
};
