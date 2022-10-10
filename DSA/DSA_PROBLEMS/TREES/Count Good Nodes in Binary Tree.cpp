/*
Count Good Nodes in Binary Tree
*/

class Solution {
public:
    int goodNodes(TreeNode* root) {
        
        return helper(root,INT_MIN);
    }
    
    int helper(TreeNode* root,int max_v)
    {
        if(!root)
            return 0;
        
        int res = root->val>=max_v ? 1 : 0;
        max_v = max(root->val,max_v);
        res+=helper(root->left,max_v);
        res+=helper(root->right,max_v);
        return res;
    }
};
