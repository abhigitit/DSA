/*
Split Array Largest Sum

Write an algorithm to minimize the largest sum among m subarrays.
Firstly, what can be the largest sum?

We need to set up a search space for the sum
If m == size of the array, we can divide the array into subarrays of length 1. Then the highest number will be the largest sum of a subarray.  This is the lower boundary.

If m==1, then the given array cannot be divided, so the sum of all elements is the sum of the subarray. This is a higher boundary.

Now we have a range and as m is fixed, we can verify if m subarrays can be formed with a certain sum as the largest sum among all divided subarrays.

If with a sum, we are able to divide the array into m or less than m subarrays, then we move towards the left to check for a lesser value of sum if this is possible else move towards right.

Helper function: Running sum and if it exceeds the sum taken from range, don't add the element. 

*/

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        int res = INT_MAX;

        while(low<=high)
        {
            int mid = low +(high-low)/2;
            if(helper(mid,nums,k))
            {
                high = mid-1;
                res = min(res,mid);
            }
            else
            {
               low = mid+1;
            }
        }
        return res;

    }

    bool helper(int mid,vector<int>& nums, int k)
    {
        int splits = 1;
        int sum = 0;
        for(int i=0;i<nums.size();++i)
        {
            if(sum+nums[i]<=mid)
                sum+=nums[i];
            else
            {
                sum=nums[i];
                splits++;
            }
                
        }
        return splits<=k;
    }
};
