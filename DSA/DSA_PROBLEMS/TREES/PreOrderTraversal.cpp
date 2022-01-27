/* Pre Order Traversal
Depth First Search can be obtained with the pre order code(Root,Left,Right) and also with reverse pre order code as well.(Root,Right,Left)
Its just that either the left or right subtree’s depth has to be visited first rather than visiting each level.
*/
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node *left;
    Node *right;
};
Node* createNode(int key){
    Node* newnode= new Node();
    newnode->key = key;
    newnode->left = NULL;
    newnode->right=NULL;
    return newnode;
}

void preOrderTraversal(Node* root)
    {
        if(root)
        {
            cout<<root->key<<"\n";
            preOrderTraversal(root->left);
            preOrderTraversal(root->right);
 
        }
    }
    
int main(){
   Node *root = createNode(6);
    root->left=createNode(5);
    root->right=createNode(4);
    root->left->left=createNode(3);
    root->right->left=createNode(2);
   preOrderTraversal(root);
    return 0;
}
