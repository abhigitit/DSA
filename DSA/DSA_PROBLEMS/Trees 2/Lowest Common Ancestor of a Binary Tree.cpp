/*
Lowest Common Ancestor of a Binary Tree (236) F

https://www.youtube.com/watch?v=WO1tfq2sbsI&ab_channel=CrackingFAANGO

O(N)
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return NULL;
        
        if(root == p or root == q)
            return root;
        
        auto l = lowestCommonAncestor(root->left,p,q);
        auto r = lowestCommonAncestor(root->right,p,q);
        
        if(l and r)
            return root;
      
        return l ? l : r;
            
    }
};
