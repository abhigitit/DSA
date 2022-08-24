#include<bits/stdc++.h>
using namespace std;

class BST{
    int val;
    BST* left;
    BST* right;
    
    public:
    BST();
    BST(int val);
    BST* insert(BST* root, int val);
    void inorder(BST* root);
    bool search_BST(BST* root, int val);
};

BST::BST()
{
    this->val = 0;
    left = nullptr;
    right = nullptr;
}


BST::BST(int val)
{
    this->val = val;
    left = nullptr;
    right = nullptr;
}

BST* BST::insert(BST* root, int val)
{
    if(!root)
    {
        
        return new BST(val);
    }
    
    if(val>root->val)
    {
        
        root->right = insert(root->right,val);
        
    }
    
    else{
        
         root->left = insert(root->left,val);
    }
 
   return root;
    
}

bool BST::search_BST(BST* root, int val)
{
    if(!root) return false;
    
    if(root->val == val)
    return true;
    
    else if(root->val <= val)
        return search_BST(root->right,val);
    
    else
    return search_BST(root->left,val);
}

void BST::inorder(BST* root)
{
    if(root)
    {
        inorder(root->left);
        cout<<root->val<<",";
        inorder(root->right);
    }
}

int main()
{
    BST b, *root = NULL;
    root = b.insert(root,6);
    b.insert(root,8);
    b.insert(root,1);
    b.insert(root,35);
    b.insert(root,77);
    b.insert(root,-9);
    b.inorder(root);
    cout<<"\n"<<"searching"<<endl;
    cout<<b.search_BST(root,7);
}
