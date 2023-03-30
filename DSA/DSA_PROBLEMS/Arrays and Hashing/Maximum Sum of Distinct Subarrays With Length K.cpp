/*
 Maximum Sum of Distinct Subarrays With Length K
 Map to check duplicates in the window
 
 */
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        map<int,int> check;
        long long sum = 0;
        long long res = 0;
        for(int i=0;i<k-1;++i)
        {
            sum+=nums[i];
            check[nums[i]]++;
        }

        for(int i=k-1;i<nums.size();++i)
        {
            sum+=nums[i];
            check[nums[i]]++;
            if(check.size()==k)
            {
                res = max(res, sum);
            }

            if(check[nums[i-k+1]]==1)
                check.erase(nums[i-k+1]);
            else
                check[nums[i-k+1]]--;
            
            sum-=nums[i-k+1];
            

        }
        return res;
    }
};
