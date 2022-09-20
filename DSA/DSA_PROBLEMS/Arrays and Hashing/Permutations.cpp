/*

Permutations
Leetcode: 46

TC: O(n*n!)
*/

class Solution {
public:
    vector<int> ds;
    map<int,int> store;
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        permute_helper(nums);
        return res;
    }
    
    void permute_helper(vector<int>& nums)
    {
        if(ds.size()==nums.size())
        {
            res.push_back(ds);
        }
        for(int i=0;i<nums.size();++i)
        {
            if(store.find(nums[i])==store.end())
            {
                store[nums[i]] = 1;
                ds.push_back(nums[i]);
                permute_helper(nums);
                ds.pop_back();
                store.erase(nums[i]);
            }
        }
    }
};
