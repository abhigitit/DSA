/*
Maximum Sum Circular Subarray

Maximum sum subarray = maximum sum (kadane's) straight subarray OR max sum with wrap around.
If max sum is in wrap around, then it is equal to = total sum - min sum subarray.

so res - max(maxSoFar,sum-minSoFar).

However there is one edge case=>all elements are negative. In that case maxSoFar will be < 0 and we should return maxSoFar.

*/
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
              int maxSoFar = nums[0];
        int maxTillHere = 0;
        int minSoFar = nums[0];
        int minTillHere = 0;
        int sum = 0;
        for(int i=0;i<nums.size();++i) {
           
            maxTillHere = max(nums[i],maxTillHere+nums[i]);
            maxSoFar = max(maxSoFar,maxTillHere);
           
            sum+=nums[i];

            minTillHere = min(nums[i],minTillHere+nums[i]);

            minSoFar = min(minSoFar,minTillHere);

        }

        return maxSoFar<0 ? maxSoFar : max(maxSoFar,sum-minSoFar);

    }
};
