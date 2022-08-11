/*

Leetcode: 366

Intution : Traverse post order to reach children first before parent.
https://www.youtube.com/watch?v=1T7vwABgiys&ab_channel=CrackingFAANG

We can maintain a map with level as key and deleted elements as list.

*/

class Solution {
public:
    map<int,vector<int>> store;
    vector<vector<int>> res;
    vector<vector<int>> findLeaves(TreeNode* root) {
        dfs(root,0);
        for(auto s:store)
        {
            res.push_back(s.second);
        }
        return res;
    }
      
    int dfs(TreeNode* root, int layer)
    {
        if(!root) return layer;
        
        int left = dfs(root->left,layer);
        int right = dfs(root->right,layer);
        
         layer = max(left,right);
         store[layer].push_back(root->val);
         return layer+1;
    }
    
};
