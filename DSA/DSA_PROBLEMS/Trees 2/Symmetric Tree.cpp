
/*
root, left , right traversal should be same to root right left traversa
*/

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }
    bool isMirror(TreeNode* n1, TreeNode* n2) {
        if (n1 == NULL || n2 == NULL) {
            return n1==n2;
        }
        return n1->val == n2->val && isMirror(n1->right, n2->left) && isMirror(n1->left, n2->right);
    }
};
