/*
Maximum Width of Binary Tree

Intuition : It is similar to finding how many nodes are there in between first and last node of the same level.
Level Order Traversal with indexing!

https://www.youtube.com/watch?v=Y2CKCnQfHJQ&ab_channel=AyushiSharma

*/

typedef pair<TreeNode*,long> p;
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
    long width = 0;
        queue<p> BFS;
        BFS.push({root,0});
        while(!BFS.empty())
        {
        int n = BFS.size();
        long first = BFS.front().second;
        long last = BFS.back().second;
        
        width = max(width,last-first+1);
        for(int i=0;i<n;++i)
        {
        p curr = BFS.front();
        TreeNode* temp = curr.first;
        long idx = curr.second-first; // it should be just curr.second for index calculation but this avoids overflow.
        BFS.pop();
        if(temp->left)
            BFS.push({temp->left,2*idx+1});
         
         if(temp->right)
            BFS.push({temp->right,2*idx+2}); 
        }
      
     
        }
        return width;
    }
};
