

/*
Leetcode: 572
Intuition : If subroot is null, then return true because null tree is subtree of any tree.
If subroot is present and root is null, return false; not possible.

If they both are same tree, return true.
Or
Find the subroot in main tree's root's left part OR right part.


Same tree Intuition: Both null trees are same, so return true as base case for both null trees.
If values at both roots are same check fro both leftsubtree AND rightsubtree.
TC : O(N)
*/
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
       if(!subRoot)
           return true;
        if(!root)
            return false;
        
        if(isSameTree(root,subRoot))
            return true;
        
        return isSubtree(root->left,subRoot) or isSubtree(root->right,subRoot);
    }
    
    bool isSameTree(TreeNode* p,TreeNode* q)
    {
        if(!p and !q)
            return true;
        if(p and q and p->val==q->val) return isSameTree(p->left,q->left) and isSameTree(p->right,q->right) ;
        return false;
    }
};
