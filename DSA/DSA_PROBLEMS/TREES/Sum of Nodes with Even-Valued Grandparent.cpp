/*

Intuition : Change curr, parent, grand parent in recursive calls
*/
class Solution {
public:
   
    int sumEvenGrandparent(TreeNode* root) {
        int res=0;
        helper(root,nullptr,nullptr,res);
       return res;
    }
    
    void helper(TreeNode* curr,TreeNode* p,TreeNode* gp,int&res)
    {
        if(!curr) return;
        
        if(gp and gp->val%2==0)
            res+=curr->val;
        
        helper(curr->left,curr,p,res);
        helper(curr->right,curr,p,res);
    }
};

