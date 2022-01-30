#include <bits/stdc++.h>
#include <queue>

using namespace std;

/* Properties of Binary Tree
Search an element
level order traversal(BFS)
Inorder, preorder(DFS), postorder traversals
right view,left view, top view, bottom view
height, diameter
*/

class BinaryTree{
    public:
    int val;
    BinaryTree* left;
    BinaryTree* right;
    vector<int> temp1;
    vector<int> temp2;
    map<int,pair<BinaryTree*, int>> store1;
    map<int,pair<BinaryTree*, int>> store2;
    BinaryTree(int value){
        val = value;
        left = nullptr;
        right = nullptr;
    }
   void printMyBinaryTree(BinaryTree* root){
       if(root)
       {
           cout<<root->val<<" ";
           printMyBinaryTree(root->left);
           printMyBinaryTree(root->right);
       }
   }
   
   //Search if an element is present in the Binary BinaryTree
   
  void searchMyBinaryTree(BinaryTree* root,int key)
  {
      BinaryTree* temp = nullptr;
      queue<BinaryTree*> q;
      q.push(root);
      while(!q.empty())
      {
          temp = q.front();
          q.pop();
          if(temp->val == key) cout<<"Found the target "<<key<<endl;
          if(temp->left!=nullptr) q.push(temp->left);
          if(temp->right!=nullptr) q.push(temp->right);
      }
      
  }
  
  //Level Order traversal OR Breadth First search
  void levelOrderTraversal(BinaryTree* root)
  {
      BinaryTree* temp = nullptr;
      queue<BinaryTree*> q;
      q.push(root);
      while(!q.empty())
      {
          temp = q.front();
          q.pop();
          cout<<temp->val<<" ";
          if(temp->left!=nullptr) q.push(temp->left);
          if(temp->right!=nullptr) q.push(temp->right);
      }
      
  }
  
  //Pre Order traversal or the Depth FIrst Search
  void preOrderTraversal(BinaryTree* root){
      if(root)
      {
          cout<<root->val<<" ";
          preOrderTraversal(root->left);
          preOrderTraversal(root->right);
      }
  }
  
  //In Order traversal 
  void inOrderTraversal(BinaryTree* root){
      if(root)
      {
          inOrderTraversal(root->left);
          cout<<root->val<<" ";
          inOrderTraversal(root->right);
      }
  }
  
   //Post Order traversal 
  void postOrderTraversal(BinaryTree* root){
      if(root)
      {
          postOrderTraversal(root->left);
          postOrderTraversal(root->right);
          cout<<root->val<<" ";
      }
  }
  
  //Right View (Reverse Pre order traversal with constraint)
  void rightView(BinaryTree* root, int level){
      if(root)
      {
          if(temp1.size()==level)
          {
              cout<<root->val<< " ";
              temp1.push_back(root->val);
          }
          rightView(root->right,level+1);
          rightView(root->left,level+1);
          
      }
  }
  
  //Left View (Pre order traversal with constraint)
  void leftView(BinaryTree* root, int level){
      if(root)
      {
          if(temp2.size()==level)
          {
              cout<<root->val<< " ";
              temp2.push_back(root->val);
          }
          leftView(root->left,level+1);
          leftView(root->right,level+1);
          
          
      }
  }
  
  //Top View
  void topView(BinaryTree* root, int level, int dist)
  {
      if(root){
          topView(root->left,level+1,dist-1);
          
          if(store1.find(dist)==store1.end() || level<store1[dist].second)
          store1[dist] = make_pair(root,level);
          topView(root->right,level+1,dist+1);
      }
  }
  
  void printTopView(){
      for(auto i:store1){
          printKey(store1[i.first].first);
      }
  }
  
  void printKey(BinaryTree* root){
      if(root)
      {
         cout<<root->val<<" "; 
      }
      
  }
  
  //Bottom View
  void bottomView(BinaryTree* root, int level, int dist)
  {
      if(root){
          bottomView(root->left,level+1,dist-1);
          
          if(store2.find(dist)==store2.end() || level>store2[dist].second)
          store2[dist] = make_pair(root,level);
          bottomView(root->right,level+1,dist+1);
      }
  }
  
  void printbottomView(){
      for(auto i:store2){
          printKey(store2[i.first].first);
      }
  }
  
  //Height of Binary tree
  int height(BinaryTree* root){
      if(!root) return 0;
      int h;
      int Lheight=height(root->left);
      int Rheight=height(root->right);
      if(Lheight>Rheight)
      h= 1+ Lheight;
      else
      h= 1+ Rheight;
      return h;
  }
  
  //Diameter of Binary tree
  int diameter(BinaryTree* root){
      if(!root) return 0;
      int Lheight = height(root->left);
      int Rheight = height(root->right);
      int Ldiameter = diameter(root->left);
      int Rdiameter = diameter(root->right);
      int diameter = max(Lheight+Rheight+1, max(Ldiameter,Rdiameter));
      return diameter;
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
  cout<<"My Binary Tree "<<" ";
  root->printMyBinaryTree(root);
  cout<<"\n";
  root->searchMyBinaryTree(root,5);
  cout<<"Breadth First Search ";
  root->levelOrderTraversal(root);
  cout<<"\n";
  cout<<"Depth First Search ";
  root->preOrderTraversal(root);
  cout<<"\n";
  cout<<"In Order Traversal ";
  root->inOrderTraversal(root);
  cout<<"\n";
  cout<<"Post Order Traversal ";
  root->postOrderTraversal(root);
  cout<<"\n";
  cout<<"Right View ";
  root->rightView(root,0);
  cout<<"\n";
  cout<<"Left View ";
  root->leftView(root,0);
  cout<<"\n";
  cout<<"Top View ";
  root->topView(root,0,0);
  root->printTopView();
  cout<<"\n";
  cout<<"Bottom View ";
  root->bottomView(root,0,0);
  root->printbottomView();
  cout<<"\n";
  cout<<"Height of Binary tree "<<root->height(root);
   cout<<"\n";
  cout<<"Diameter of Binary tree "<<root->diameter(root);
  
    return 0;
}
