#include <bits/stdc++.h>
using namespace std;
struct BST{
    int val;
    BST* left;
    BST* right;
};

BST* newNode(int data)
{
    BST* root = new BST();
    root->val = data;
    root->left = root->right = nullptr;
    return root;
}

BST* insert(BST* root,int data){
    if(!root)
    {
        root = newNode(data);
        return root;
    }
    if(root->val>=data)
    {
        root->left = insert(root->left,data);
    }
    else if(root->val<data)
    {
        root->right = insert(root->right,data);
    }
    return root;
}

void printBST(BST* root)
{
    if(root)
    {
        printBST(root->left);
        cout<<root->val<<endl;
        printBST(root->right);
    }
}

int main()
{
    BST* root = nullptr;
    root = newNode(6);
    root = insert(root,5);
    root = insert(root,10);
    root = insert(root,4);
    root = insert(root,15);
    printBST(root);

    return 0;
}
