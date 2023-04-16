/*
Inorder traversal : First value we encounter which is greater than x, thats the answer.
*/

class Solution {
    TreeNode* res;
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        res = nullptr;
        bool flag = true;
        helper(root,p,flag);
        return res;
    }
    
    void helper(TreeNode* node,TreeNode* p,bool &flag)
    {
        if(!node) return;
        
        helper(node->left,p,flag);
        if(node->val>p->val and flag)
        {
            res = node;
            flag = !flag;
            return;
        }
        helper(node->right,p,flag);
    }
};
