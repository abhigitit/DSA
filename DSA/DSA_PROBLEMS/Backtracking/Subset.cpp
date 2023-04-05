/*
Subset
*/

class Solution {
    vector<vector<int>> res;
    vector<int> subset;
    void dfs(int i,vector<int>& nums)
    {
        if(i>=nums.size())
        {
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        dfs(i+1,nums);

        subset.pop_back();
        dfs(i+1,nums);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0,nums);
        return res;
    }
};
