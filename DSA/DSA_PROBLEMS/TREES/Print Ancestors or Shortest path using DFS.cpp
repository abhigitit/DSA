
/*
Print Ancestors or Shortest path using DFS.cpp
https://www.youtube.com/watch?v=qjD-CmuC0MQ&ab_channel=Vivekanand-AlgorithmEveryDay
*/

#include <bits/stdc++.h>


using namespace std;

vector<int> res;
class BinaryTree{
    public:
    int val;
    BinaryTree* left;
    BinaryTree* right;
    BinaryTree(int value){
        val = value;
        left = nullptr;
        right = nullptr;
    }

int print_ancestors(BinaryTree* root, int target)
{
    
    if(root)
    {
        if(root->val == target) return 1;
        if(print_ancestors(root->left,target) || print_ancestors(root->right,target))
        {
           res.push_back(root->val);
           return 1;
        }
        
    }
    return 0;
}
  
 
    
};

int main()
{
    BinaryTree* root = new BinaryTree(6);
    root->left = new BinaryTree(5);
    root->right = new BinaryTree(4);
    root->left->right = new BinaryTree(3);
    root->left->left = new BinaryTree(2);
    root->left->left->left = new BinaryTree(21);
    root->right->left = new BinaryTree(1);
    root->right->right = new BinaryTree(0);
    root->right->right->left = new BinaryTree(-1);
    root->right->right->right = new BinaryTree(-2);
    /*
      6 
     / \
    5   4
   /\  / \
  2  3 1  0 
 /       / \
21     -1  -2  
*/
int target = 21;
 root->print_ancestors(root,target);
 cout<<"Ancestors of target"<<endl;
  for(auto i:res)
  {
      cout<<i<<" ";
  }
  cout<<"\n";
  reverse(res.begin(),res.end());
  res.push_back(target);
  cout<<"Shortest path till target using DFS"<<endl;
   for(auto i:res)
  {
      cout<<i<<" ";
  }
    return 0;
}
