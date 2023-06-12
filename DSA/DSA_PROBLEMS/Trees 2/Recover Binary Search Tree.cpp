/* https://www.youtube.com/watch?v=ZWGW7FminDM
*/
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* first = nullptr;
        TreeNode* middle = nullptr;
        TreeNode* second = nullptr;
        TreeNode* prev = nullptr;
        
        inorder(root, first, middle, second, prev);
        
        if (first && second) {
            swap(first->val, second->val);
        } else if (first && middle) {
            swap(first->val, middle->val);
        }
    }
    
private:
    void inorder(TreeNode* root, TreeNode*& first, TreeNode*& middle, TreeNode*& second, TreeNode*& prev) {
        if (!root) {
            return;
        }
        
        inorder(root->left, first, middle, second, prev);
        
        if (prev && root->val < prev->val) {
            if (!first) {
                first = prev;
                middle = root;
            } else {
                second = root;
            }
        }
        
        prev = root;
        
        inorder(root->right, first, middle, second, prev);
    }
};
