/*
Height of Binary Tree After Subtree Removal Queries

https://www.youtube.com/watch?v=lfNDnO971Ys

value : start time, value : end time 
depth[starttime] = depth

basically start time is numbering of nodes.

compute all heights before hand so that its O(1) operation for query.

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
class Solution {
    map<int,int> start,end,depth;
    int time = 0;
    vector<int>suff;
    vector<int>pref;
    void helper(TreeNode* root,int d)
    {
        start[root->val] = ++time;
        depth[start[root->val]] = d;
        if(root->left)
            helper(root->left,d+1);
        if(root->right)
            helper(root->right,d+1);
        
        end[root->val] = time;
    }
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        helper(root,0);
        int n = depth.size();
        suff.resize(n+2);
        pref.resize(n+2);

        for(int i=1;i<n;++i)
        {
            pref[i] = max(pref[i-1],depth[i]);
        }

         for(int i=n;i>=0;i--)
        {
            suff[i] = max(suff[i+1],depth[i]);
        }

        vector<int>ans;
        int q = queries.size();

        for(int i=0;i<q;++i)
        {
           int st= start[queries[i]]-1;
           int ed = end[queries[i]]+1;
           ans.push_back(max(pref[st],suff[ed]));
        }
        return ans;

    }
};
