/*
3Sum
TakeU
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        for(int i=0;i<n-2;++i)
        {
            if(i==0 or (i>0 and nums[i]!=nums[i-1]))
            {
            int low = i+1;
            int high = n-1;
            int sum = -(nums[i]);

            while(low<high)
            {
                if(nums[low]+nums[high]==sum)
                {
                    res.push_back({nums[i],nums[low],nums[high]});
                    while(low<high and nums[low]==nums[low+1]) low++;
                    while(low<high and nums[high]==nums[high-1]) high--;
                    low++;
                    high--;
                }
                else if(nums[low]+nums[high]>sum)
                    high--;
                else
                    low++;
            }
            }
            
        }
        return res;
    }
};
