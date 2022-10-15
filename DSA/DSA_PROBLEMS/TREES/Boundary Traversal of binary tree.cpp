/*
Boundary Traversal of binary tree

1) LEFT boundary excluding leaves
2) Leaves
3) Right boundary in reverse

*/

class Solution {
public:
    vector<int> res;
    vector<int> temp;
    void leftBoundary(Node *root)
    {
        Node *curr = root->left;
        while(curr)
        {
            if(!isLeaf(curr)) res.push_back(curr->data); 
            if(curr->left) curr = curr->left;// If there is left, it will be on the boundary
            else curr = curr->right;// else right node will be the boundary
        }
    }
      void rightBoundary(Node *root)
    {
        Node *curr = root->right;
        while(curr)
        {
            if(!isLeaf(curr)) temp.push_back(curr->data);
            if(curr->right) curr = curr->right;
            else curr = curr->left;
        }
        
        for(int i=temp.size()-1;i>=0;--i)
        {
            res.push_back(temp[i]);
        }
    }
    
    void addLeaves(Node *root)
    {
        if(root)
        {
        if(isLeaf(root))
        {
          res.push_back(root->data);
        }
        
        addLeaves(root->left);
        addLeaves(root->right);
        }
       
    }
    bool isLeaf(Node *root)
    {
        if(!root->left and !root->right)
        return true;
        
        return false;
    }
    vector <int> boundary(Node *root)
    {
        if(!root) return {};
        if(!isLeaf(root)) res.push_back(root->data);
        leftBoundary(root);
        addLeaves(root);
        rightBoundary(root);
        return res;
    }
};
