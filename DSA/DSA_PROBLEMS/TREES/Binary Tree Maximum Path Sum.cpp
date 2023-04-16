/*

Leetcode: Binary Tree Maximum Path Sum
https://www.youtube.com/watch?v=JBYs5J4skZE

TC:O(N)

*/

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        helper(root,ans);
        return ans;
    }

    int helper(TreeNode* root, int& ans)
    {
        if(!root) return 0;

        int left = helper(root->left,ans);
        int right = helper(root->right,ans);

        int straightPath = max(root->val , max(root->val+left,root->val+right));
        int curvedPath = left + right + root->val;
        ans = max(ans,max(straightPath,curvedPath));
        return straightPath;
    }
};
