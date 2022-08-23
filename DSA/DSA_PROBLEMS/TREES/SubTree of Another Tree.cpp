

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
