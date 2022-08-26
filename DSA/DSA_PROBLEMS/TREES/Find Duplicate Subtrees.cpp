/*
Leetcode: 652

Intuition : Store every subtree as a string in a map. Push to result if we already have seen it.

TC:O(n)
SC:O(n)

*/

class Solution {
public:
    unordered_map<string,int> seen;
    vector<TreeNode*> res;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        helper(root);
        return res;
    }
    
    string helper(TreeNode* root)
    {
        if(!root) return "#";
        string path = to_string(root->val) + ',' + helper(root->left) + ',' + helper(root->right);
        if(seen.find(path)!=seen.end())
        {
            if(seen[path]==1)
            {
                res.push_back(root);
                seen[path]++;
            }
            
        }
        else
                seen[path]++;
            return path;
    }
};
