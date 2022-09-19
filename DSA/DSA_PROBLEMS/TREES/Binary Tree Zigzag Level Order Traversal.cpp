/*
Binary Tree Zigzag Level Order Traversal
Leetcode: 103

*/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
      vector<vector<int>> res;
       TreeNode* out = nullptr;
        queue<TreeNode*> q;
        q.push(root);
        int flag = 1;
        while(!q.empty())
        {
            int len = q.size();
            vector<int> temp;
            
            for(int i=0;i<len;++i)
            {
                out = q.front();
                temp.push_back(out->val);
                q.pop();
                if(out->right) q.push(out->right);
                if(out->left) q.push(out->left);
            }
            
            if(flag%2==0)
            res.push_back(temp);
            else
            {
                reverse(temp.begin(),temp.end());
                res.push_back(temp);
            }
            flag++;
               
        }
        return res;
    }
};
