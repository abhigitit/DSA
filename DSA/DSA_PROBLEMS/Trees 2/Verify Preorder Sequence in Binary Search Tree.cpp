/*
Verify Preorder Sequence in Binary Search Tree
first greater element to right is my right child and all elements to my 
right child should be greater than me. Bruteforce check this for all elements.
https://www.youtube.com/watch?v=GYdC4hQSo8A

*/

class Solution {
    
public:
    bool verifyPreorder(vector<int>& preorder) {
        int root = INT_MIN;
        stack<int> dec;
        for(int i=0;i<preorder.size();++i) {
            
            while(dec.size() and preorder[i]>dec.top())
            {
                root=dec.top();
                dec.pop();
            }
            
            if(preorder[i]<root) return false;
            
            dec.push(preorder[i]);
        }
        return true;
    }
};
