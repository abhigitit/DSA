/*
Height of Binary tree(Max Depth)
https://www.youtube.com/watch?v=_O-mK2g_jhI&ab_channel=VivekanandKhyade-AlgorithmEveryDay

Height= 1 + no of edges in the longest path
Height of the root is the height of the BT.

Algorithm :
1)If root is null, return 0;
2)Recursively move to the left most leaf node to calculate the height of every node from the bottom.
3)Recursively move right so that max of left,right heights are passed at each step.
4)Check if left>right or not and return left+1 or right+1 accordingly.
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

int height(Node* root)
{
if(!root)
    return 0;
int h;
int Lheight = height(root->left);
int Rheight = height(root->right);
if(Lheight>Rheight)
    h= Lheight+1;
else
    h= Rheight +1;
return h;
}


int main(){
   Node *root = createNode(6);
    root->left=createNode(5);
    root->right=createNode(4);
    root->left->left=createNode(3);
    root->right->left=createNode(2);
    cout<<height(root);
 
    return 0;
}
