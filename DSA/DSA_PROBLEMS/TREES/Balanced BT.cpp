/*
Leetcode: 110

Intuition : If we take top down approach and as each node if its left and right subtrees are balanced, it takes O(n^2).
We can take bottom up approach by traversing to the child node first and bubble up the boolean value and height of the tree.

https://www.youtube.com/watch?v=QfJsau0ItOY&ab_channel=NeetCode

TC:O(N)

*/

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root).first;
    }
    
    pair<bool,int> dfs(TreeNode* root){
       if(!root) return make_pair(true,0);
        
        pair<bool,int> left = dfs(root->left);
        pair<bool,int> right = dfs(root->right);
        bool balanced = (left.first and right.first and abs(left.second - right.second) <= 1);
        return make_pair(balanced,1+max(left.second,right.second));
    }
};
