/*
BST Iterator

Iterative DFS
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
    stack<TreeNode*>inorder;
    void dfs(TreeNode* root)
    {
        while(root)
        {
            inorder.push(root);
            root=root->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        dfs(root);
    }
    
    int next() {
        auto x = inorder.top();
        inorder.pop();
        auto node = x->right;
        dfs(node);
        return x->val;
    }
    
    bool hasNext() {
        return inorder.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
