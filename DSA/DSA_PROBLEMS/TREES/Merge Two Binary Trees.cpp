/*
Leetcode : 617

Intuition: If both roots are not null, create new tree node with root1 and root2 values and recursilevly call for left and right subtrees.
If either of the tree's root is null, return other tree root.

TC : O(N+M) where N is elements of first tree and M is elements of second tree
*/

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 and root2)
        {
            TreeNode* root3 = new TreeNode(root1->val+root2->val);
            root3->left = mergeTrees(root1->left,root2->left);
            root3->right = mergeTrees(root1->right,root2->right);
            return root3;
        }
        return root1 ? root1 : root2;
    }
};
