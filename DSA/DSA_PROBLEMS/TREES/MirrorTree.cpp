/* Mirror view of Binary Tree
Algorithm:
If root is not null, enter the program.
Travel to the leftmost leaf node recursively. 
Travel to the right nodes recursively
Swap left nodes with right nodes using a node* temp.
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

void Print(Node *root)
{
  if(root)
  {
cout<<root->key<<"\n";
Print(root->left);
Print(root->right);
  }
}

void mirror(Node* root)
{
if(root)
{
mirror(root->right);
mirror(root->left);
Node* temp = root->right;
root->right = root->left;
root->left=temp;
}
return;
}

int main(){
   Node *root = createNode(6);
    root->left=createNode(5);
    root->right=createNode(4);
    root->left->left=createNode(3);
    root->right->left=createNode(2);
    Print(root);
    mirror(root);
    cout<<"______"<<"\n";
    Print(root);
 
    return 0;
}
