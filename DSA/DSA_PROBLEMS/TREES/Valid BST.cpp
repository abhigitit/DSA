/*
Leetcode: 98

Intuition : Every element in the left subtree should be smaller than the root and elements in the right subtree are greater than the root.
To perform the solution in linear time, we use this approach.

Root value is always between -INF, +INF.
When we move to the immediate left child of the root, that child should be in the range of -INF, Root
and if we move to the immediate right child of the root, that child should be in the range of Root, +INF

We check if the tree is null, then return true as a null tree in BST.


return helper(root->left,left,root->val) and helper(root->right,root->val,right); we call the respective subtrees updating the range

*/


class Solution {
public:
    bool isValidBST(TreeNode* root) {
        
        return helper(root,LONG_MIN,LONG_MAX);
    }
    
    bool helper(TreeNode* root,long left,long right)
    {
        if(!root) return true;
        
        if(!(root->val>left and root->val<right))
            return false;
        
        return helper(root->left,left,root->val) and helper(root->right,root->val,right);
    }
};
