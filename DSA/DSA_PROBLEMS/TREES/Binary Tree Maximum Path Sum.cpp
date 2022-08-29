/*

Leetcode: Binary Tree Maximum Path Sum
https://www.youtube.com/watch?v=cSnETAcziS0&ab_channel=GeeksforGeeks
Intution : At every root, the max value can be root->val or max(left child value , right child val) + root->val
At top root, both right and left paths can be considered so maxAtTopRoot = max(maxAtRoot,l+r+root->val);

TC:O(N)

*/

class Solution {
public:
    int res;
    int maxPathSum(TreeNode* root) {
        res = INT_MIN;
        helper(root);
        return res;
    }
    
    int helper(TreeNode* root)
    {
        if(!root) return 0;
        
        int l = helper(root->left);
        int r = helper(root->right);
        int maxAtRoot = max(root->val,max(l,r)+root->val);
        int maxAtTopRoot = max(maxAtRoot,l+r+root->val);
        res = max(res,maxAtTopRoot);
        return maxAtRoot;
    }
};
