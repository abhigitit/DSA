/* Level Order Traversal
Breadth First Search can be obtained with the same code
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
void levelOrderTraversal(Node* root){
    if(root != NULL){
    Node* temp = NULL;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        temp = q.front();
        q.pop();
        cout<<temp->key<<"\n";
        if(temp->left!=NULL) q.push(temp->left);
        if(temp->right!=NULL) q.push(temp->right);
        }
}
}
int main(){
   Node *root = createNode(6);
    root->left=createNode(5);
    root->right=createNode(4);
    root->left->left=createNode(3);
    root->right->left=createNode(2);
    levelOrderTraversal(root);
    return 0;
}
