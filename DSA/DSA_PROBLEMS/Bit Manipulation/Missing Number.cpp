/*
Leetcode: 268

Intuition : Xor all elements in the array and store in res;
Then Xor the res with numbers from 0 to n to find which is missing. return res

*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        int temp =0;
        int i=0;
       for(int i=0;i<nums.size();++i)
       {
           temp^=nums[i];
       }
         for(int i=0;i<=nums.size();++i)
       {
           temp^=i;
       }
        return temp;
    }
};
