/*
Count Good Nodes in Binary Tree
*/

class Solution {
    int count = 0;
    void helper(TreeNode* root, int maxe)
    {
        if(!root)
            return;
        if(root->val>=maxe)
        {
            count++;
            maxe=root->val;
        }
        helper(root->left,maxe);
        helper(root->right,maxe);
    }
public:
    int goodNodes(TreeNode* root) {

        helper(root,root->val);
        return count;
    }
};
