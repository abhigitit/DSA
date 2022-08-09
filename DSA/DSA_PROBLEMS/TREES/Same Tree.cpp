/*
Leetocde : Same Tree

Intuition: Both null trees are same, so return true as base case for both null trees.
If values at both roots are same check fro both leftsubtree AND rightsubtree.

TC : O(N)

*/


class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p and !q) return true;
        if(p and q and p->val==q->val) return isSameTree(p->left,q->left) and isSameTree(p->right,q->right);
        return false;
    }
};
