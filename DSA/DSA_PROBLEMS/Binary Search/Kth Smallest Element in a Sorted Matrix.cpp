/*
Kth Smallest Element in a Sorted Matrix
Leetcode 378
https://www.youtube.com/watch?v=b4mkk8Fk8fs&ab_channel=ifelsestatement

*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int min = matrix[0][0];
        int max = matrix[n-1][n-1];
        
        while(min!=max)
        {
            int mid = min + (max-min)/2;
            int count = countLessEqual(matrix,mid);
            if(count<k)
                min = mid+1;
            else
                max = mid;
             
        }
        return min;
    }
    
    int countLessEqual(vector<vector<int>> matrix,int mid)
    {
        int i=0;
        int j=matrix.size()-1;
        int count =0;
        while(i<matrix.size() and j>=0)
        {
            if(matrix[i][j]<=mid)
            {
                count+= j+1;
                i++;
            }
            else
                j--;
                
        }
        return count;
    }
};
