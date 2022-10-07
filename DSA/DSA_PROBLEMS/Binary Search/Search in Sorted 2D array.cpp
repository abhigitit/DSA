/*

Search in Sorted 2D array

Intuition : To perform in O(logN) start at first row, last col and eliminate half of the options at each step.

*/


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row =0;
        int col = matrix[0].size()-1;
        
        while(row<matrix.size() and col>=0)
        {
            if(matrix[row][col]>target)
                col--;
            else if(matrix[row][col]<target)
                row++;
            else
                return true;
        }
        return false;
    }
};
