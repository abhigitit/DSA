/*
Max diff between Node and Ancestor.cpp
Leetcode: 1026

*/

class Solution {
public:
    /*
	     Given Example - 1 in Question :
		 all paths or Sequences given below :
		 
		* 		 8->3->1            (mx = 8 , mi = 1)  ==> diff = mx - mi = 8 - 1 = 7
		* 		 8->3->6->4         (mx = 8 , mi = 3)  ==> diff = mx - mi = 8 - 3 = 5
		* 		 8->3->6->7         (mx = 8 , mi = 3)  ==> diff = mx - mi = 8 - 3 = 5
		* 		 8->10->14->13      (mx = 14, mi = 8)  ==> diff = mx - mi = 14 - 8 = 6
	     
		 maximum of all the "diff" values is the required answer.
		 so answer is diff = 7.
	*/
    int diff = INT_MIN; // we want max difference
    
    void getMax(TreeNode *root, int mx, int mi){
        
        if(!root) return;
        
        // track minimum and maximum while going through a sequence or path
        mx = max(mx, root->val);
        mi = min(mi, root->val);
        
        diff = max(diff, mx - mi); // store maximum difference
        
        getMax(root->left,mx,mi);
        getMax(root->right,mx,mi);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        
        if(!root) return 0;
        
        int mx = INT_MIN, mi = INT_MAX;

        getMax(root,mx,mi);
        
        return diff;
    }
};
