
/*
Leetcode: Binary Tree Level Order Traversal II

*/

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> helper_q;
        stack<vector<int>> helper_st;
        helper_q.push(root);
        
        while(!helper_q.empty())
        {
            int n = helper_q.size();
            vector<int> vec;
            for(int i=0;i<n;++i)
            {
                TreeNode* temp = helper_q.front();
                helper_q.pop();
                vec.push_back(temp->val);
                if(temp->left) helper_q.push(temp->left);
                if(temp->right) helper_q.push(temp->right);
            }
            
            helper_st.push(vec);
            
        }
        while(!helper_st.empty())
        {
            res.push_back(helper_st.top());
            helper_st.pop();
        }
        return res;
    }
};
