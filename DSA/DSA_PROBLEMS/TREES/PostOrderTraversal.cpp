/* Post Order traversal of BT
 YT : https://www.youtube.com/watch?v=4Xo-GtBiQN0&ab_channel=ygongcode
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

void postOrderTraversal(Node* root)
    {
        if(root)
        {
            cout<<root->key<<"\n";
            postOrderTraversal(root->left);
            postOrderTraversal(root->right);
        }
    }
    
int main(){
   Node *root = createNode(6);
    root->left=createNode(5);
    root->right=createNode(4);
    root->left->left=createNode(3);
    root->right->left=createNode(2);
    postOrderTraversal(root);
    return 0;
}
