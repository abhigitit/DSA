/*
Leetcode: 543
https://www.youtube.com/watch?v=ey7DYc9OANo&ab_channel=Vivekanand-AlgorithmEveryDay

*/

DP:
int ans = INT_MIN;
int height(TreeNode* root) {
    if(!root) return 0;
    int lft = height(root->left);
    int rgt = height(root->right);
    ans = max( ans , 1+lft+rgt);//add this line while calculating height
    return lft>rgt ?1+lft : 1+rgt;
    
}
___________
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
          int l = height(root->left);
          int r = height(root->right);
        int ld = diameterOfBinaryTree(root->left);
        int rd = diameterOfBinaryTree(root->right);
        int d;
        d = max(l+r,max(ld,rd));
        return d;
        
    }
    int height(TreeNode* root)
    {
        if(!root) return 0;
        
        int l = height(root->left);
        int r = height(root->right);
        int h;
        if(l>r)
            h = l + 1;
        else
            h = r + 1;
        return h;
    }
};
