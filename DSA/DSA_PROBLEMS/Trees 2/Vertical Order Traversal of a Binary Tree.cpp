/*

Vertical Order Traversal of a Binary Tree

Extension of top view

Own Sol
*/

class Solution {
    vector<vector<int>> res;
    map<int,vector<pair<int,int>>> cache;
    void helper(TreeNode* root, int dist, int level)
    {
        if(!root) return;
        cache[dist].push_back({level,root->val});
        helper(root->left,dist-1,level+1);
        helper(root->right,dist+1,level+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        helper(root,0,0);
        for(auto it:cache)
        {
            vector<pair<int,int>> v = it.second;
            sort(v.begin(),v.end());
            vector<int> temp;
            for(auto i:v)
                  temp.push_back(i.second);
            res.push_back(temp);         
        }
        return res;
    }
};
