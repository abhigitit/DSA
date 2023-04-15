/*
Kth Smallest Element In a Bst
*/
class Solution {
    int res;
    int count;
    void helper(TreeNode* root, int k)
    {
        if(!root) return;

        helper(root->left,k);
        count++;
        if(count==k)
            res = root->val;
         helper(root->right,k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        helper(root,k);
        return res;
    }
};
