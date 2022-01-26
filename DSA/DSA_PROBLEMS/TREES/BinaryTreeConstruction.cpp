//Binary Tree Construction and Searching Element

/* Algorithm:
Declare two Node pointers (temp, out)
Declare additional space Queue which holds node * (queue<Node*> q)
Push the root element into the queue
While q is not empty, give the front value of the queue to the temp variable, pop the queue and check if the value needed is present(temp->value=value), assign the temp to out pointer variable . If the value is not found, check if temp->left and temp->right are not null and push them into the queue.
After while loop, return out pointer variable.
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
Node* searchBinaryTree(Node* root, int key){
    if(root == NULL) return NULL;
    Node* temp = new Node();
    Node* out = NULL;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(temp->key == key) {out = temp;cout<<"HIT"<<endl;}
        if(temp->left!=NULL) q.push(temp->left);
        if(temp->right!=NULL) q.push(temp->right);
        }
    return out;
}
int main(){
   Node *root = createNode(6);
    root->left=createNode(5);
    root->right=createNode(4);
    root->left->left=createNode(3);
    root->right->left=createNode(2);
    Node* node = searchBinaryTree(root,3);
    cout<<node->key<<endl;
    return 0;
}

