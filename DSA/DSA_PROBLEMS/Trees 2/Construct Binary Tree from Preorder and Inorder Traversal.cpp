Striver

class Solution {
public:
map<int,int> inorderIndex;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();++i) {
            inorderIndex[inorder[i]]=i;
        }

        return helper(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,int preStart, int preEnd, int inStart, int inEnd) {

        if(preStart>preEnd or inStart>inEnd) return nullptr;
        TreeNode* root = new TreeNode(preorder[preStart]);
        int idxIn = inorderIndex[preorder[preStart]];
        int numsLeft = idxIn-inStart;

        root->left = helper(preorder, inorder, preStart+1,preStart+numsLeft, inStart,idxIn-1);
        root->right = helper(preorder, inorder,preStart+numsLeft+1,preEnd,idxIn+1,inEnd);
        return root;
    }
};
