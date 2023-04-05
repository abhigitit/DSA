/*
Combinations
*/


class Solution {
    vector<vector<int>> res;
    vector<int> subset;
    void dfs(int start,int n, int k)
    {
        if(subset.size()==k)
        {
            res.push_back(subset);
            return;
        }

        for(int i=start;i<=n;++i)
        {
            subset.push_back(i);
            dfs(i+1,n,k);
            subset.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        dfs(1,n,k);
        return res;
    }
};
