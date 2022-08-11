

/*
Leetcode 152
Intution : Same like, max sum subarray, but we calculate minimum product so that if a negative number comes up, we can use min product for computation of max product including that number.
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxTillHere = nums[0];
        int minTillHere = nums[0];
        int maxSoFar = nums[0];
        
        for(int i=1;i<nums.size();++i)
        {
            if(nums[i]<0) swap(maxTillHere,minTillHere);
            
            maxTillHere = max(maxTillHere*nums[i], nums[i]);
            minTillHere = min(minTillHere*nums[i], nums[i]);
            maxSoFar = max(maxSoFar,maxTillHere);
        }
        return maxSoFar;
    }
};
