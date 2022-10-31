/*

Invert Binary Tree

Intuition : Traverse to the leaf nodes, swap nodes

*/

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        helper(root);
        return root;
    }
    
    void helper(TreeNode* root)
    {
        if(!root) return;
        
        helper(root->left);
        helper(root->right);
        TreeNode* temp=root->right;
        root->right = root->left;
        root->left = temp;
    }
};
