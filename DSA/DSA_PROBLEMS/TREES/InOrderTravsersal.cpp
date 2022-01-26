/*In order traversal 
YT : https://www.youtube.com/watch?v=4_UDUj1j1KQ

Note: In inorder traversal, the node is processed after the traversal of the left subtree is finished and before it starts traversing the right subtree.
If the tree is a binary search tree, output will be in ascending order.

*/

#include <bits/stdc++.h>
#include <queue>
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

void inOrderTraversal(Node* root)
    {
        if(root)
        {
            inOrderTraversal(root->left);
            cout<<root->key<<"\n";
            inOrderTraversal(root->right);
 
        }
    }
    
int main(){
   Node *root = createNode(6);
    root->left=createNode(5);
    root->right=createNode(4);
    root->left->left=createNode(3);
    root->right->left=createNode(2);
   inOrderTraversal(root);
    return 0;
}
