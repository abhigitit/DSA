/*
Combination Sum
Neetcode
*/


class Solution {
public:
vector<vector<int>> res;
int t;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        t=target;
        backtrack(0,{},0,candidates);
        return res;
    }

    void backtrack(int i,vector<int> curr,int total,vector<int>& candidates)
    {
        if(total==t)
            {
                res.push_back(curr);
                return;
            }
        if(i >= candidates.size() or total>= t)
            return;

        curr.push_back(candidates[i]);
        backtrack(i,curr,total+candidates[i],candidates);
        curr.pop_back();
        backtrack(i+1,curr,total,candidates);

    }
};
