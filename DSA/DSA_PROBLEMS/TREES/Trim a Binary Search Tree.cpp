/*
Trim a Binary Search Tree
https://www.youtube.com/watch?v=r78vqOoqMOI

*/

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return trim(root,low,high);
    }

    TreeNode* trim(TreeNode* root, int low, int high)
    {
        if(!root) return nullptr;

        TreeNode* leftNode = trim(root->left,low,high);
        if(leftNode!=root->left) root->left = leftNode;
        TreeNode* rightNode = trim(root->right,low,high);
        if(rightNode!=root->right) root->right = rightNode;

        if(root->val<low or root->val>high) return root->left ? root->left : root->right;
        return root;
    }
};
