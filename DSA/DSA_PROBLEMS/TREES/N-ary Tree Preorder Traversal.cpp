/*
 N-ary Tree Preorder Traversal
 */
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        if(!root) return res;
        helper(root,res);
        return res;
        }

        void helper(Node* root,vector<int>& res)
        {
            res.push_back(root->val);
            for(auto i:root->children)
            {
                helper(i,res);
            }
        }
    
};
