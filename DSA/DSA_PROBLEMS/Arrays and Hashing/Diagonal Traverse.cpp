/*
Leetcode: 498

Intuition : https://www.youtube.com/watch?v=FH9BxnzumVo&t=644&ab_channel=CrackingFAANG
*/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> res;
        int rows = mat.size();
        int cols = mat[0].size();
        bool going_up = true;
        int curr_row =0,curr_col=0;
        while(res.size()!=rows*cols)
        {
            if(going_up)
            {
                 while(curr_row>=0 and curr_col<cols)
            {
                res.push_back(mat[curr_row][curr_col]);
                curr_row--;
                curr_col++;
            }
            if(curr_col==cols)
            {
                curr_row+=2;
                curr_col--;
            }
            else
                curr_row++;
            going_up = false;
            }
            
            else
            {
                while(curr_col>=0 and curr_row<rows)
                {
                   res.push_back(mat[curr_row][curr_col]);
                    curr_row++;
                    curr_col--;
                }
                if(curr_row==rows)
                {
                    curr_col+=2;
                    curr_row--;
                }
                else
                    curr_col++;
                going_up=true;
            }
           
          
        }
        return res;
    }
};
