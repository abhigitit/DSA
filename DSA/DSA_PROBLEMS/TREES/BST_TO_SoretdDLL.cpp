/*
BST to Sorted Doubly Linked List (In Place)
https://www.youtube.com/watch?v=FsxTX7-yhOw&ab_channel=Vivekanand-AlgorithmEveryDay
*/


#include<bits/stdc++.h>
using namespace std;

class BST{
    public:
    int val;
    BST* left;
    BST* right;
     BST* head;
    
    BST(){
        val=0;
        left=right= head=nullptr;
    }
    
    BST(int data)
    {
        val = data;
        left=right =head= nullptr;
    }
    
    BST* insert(BST* root,int data)
    {
        if(!root){
            root = new BST(data);
            return root;
        }
        
        if(data<=root->val){
            root->left = insert(root->left,data);
        }
        else if(data>root->val)
        {
            root->right = insert(root->right,data);
        }
        return root;
    }
    
    void printBST(BST* root)
    {
        if(root){
        printBST(root->left);
        cout<<root->val<<"\n";
        printBST(root->right);
        }
        
    }
    
    void convert(BST* root,BST* head)
    {
       if(!root) return;
       static BST* prev = nullptr;
       convert(root->left,this->head);
       
       if(!prev)
       {
           this->head = root;
       }
       else{
           root->left = prev;
           prev->right = root;
       }
       prev = root;
       convert(root->right,this->head);
       
    }
    
    void printDLL()
    {
        
        while(this->head)
        {
            cout<<this->head->val<<"\n";
            this->head = this->head->right;
        }
    }
    
};


int main(){
    BST* root = new BST(6);
    root = root->insert(root,12);
    root = root->insert(root,1);
    root = root->insert(root,14);
    root = root->insert(root,18);
    root = root->insert(root,5);
  root->printBST(root);
  cout<<"__"<<endl;
   root->convert(root,nullptr);
   root->printDLL();
  
}
