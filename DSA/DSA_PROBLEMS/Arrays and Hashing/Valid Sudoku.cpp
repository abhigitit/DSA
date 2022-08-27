/*

leetcode: 36
https://www.youtube.com/watch?v=TjFXEUCMqI8&t=717s&ab_channel=NeetCode
*/


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<int,set<int>> rows;
        map<int,set<int>> cols;
        map<string,set<int>> box;
        
        for(int i=0;i<9;++i)
        {
            for(int j=0;j<9;++j)
            {
                if(board[i][j]=='.') continue;
                string key = to_string(i/3) +','+ to_string(j/3);
                if(rows[i].find(board[i][j])!=rows[i].end() or cols[j].find(board[i][j])!=cols[j].end() or box[key].find(board[i][j])!=box[key].end())
                                return false;
                                else
                                {
                                    rows[i].insert(board[i][j]);
                                    cols[j].insert(board[i][j]);
                                    box[key].insert(board[i][j]);
                                }
            
            }
                                
        }
           
                
                return true;
        
                                }                             
};
