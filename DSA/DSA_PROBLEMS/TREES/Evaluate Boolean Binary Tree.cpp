/*
Evaluate Boolean Binary Tree
*/
class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if(!root->left and !root->right)
            return root->val;
        
        bool left = evaluateTree(root->left);
        bool right = evaluateTree(root->right);
        bool res;
        if(root->val==2)
            res = left or right;
        else if(root->val==3)
            res = left and right;
        
        return res;
    }
};
