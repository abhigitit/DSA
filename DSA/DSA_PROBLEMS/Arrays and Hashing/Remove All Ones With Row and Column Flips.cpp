/*
Leetcode: Remove All Ones With Row and Column Flips

Intuition : Fix first row by flipping all columns where there is 1 in the first row. This means we cannot touch the first row again as all are zeroes now.
If we cannot change first row, we technically cant change any column. So eveyrthing must be in place in entire matrix. Either all 0s or all 1s in the rows.

*/

class Solution {
public:
    bool removeOnes(vector<vector<int>>& grid) {
        
        for(int i=0;i<grid[0].size();++i)
        {
            if(grid[0][i]==1)
            {
                for(int j=0;j<grid.size();++j)
                {
                    grid[j][i] = !grid[j][i];
                }
            }
        }
        
        int count=0;
        for(int i=1;i<grid.size();++i)
        {
            count = 0;
            for(int j=0;j<grid[i].size();++j)
            {
                count+=grid[i][j];
            }
            if(count!=0 and count!=grid[i].size())
                return false;
        }
        
        return true;
    }
};
