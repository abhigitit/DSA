/*
Leetcode: 419
Same as Number of islands
*/

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
       int res = 0;
        for(int i=0;i<board.size();++i)
        {
            for(int j=0;j<board[i].size();++j)
            {
                if(board[i][j]=='X')
                {
                    res++;
                    DFS(i,j,board);
                }
                    
            }
        }
        return res;
    }
    
    void DFS(int i,int j, vector<vector<char>>& board)
    {
        if(i<0 or j<0 or i>=board.size() or j>=board[i].size() or board[i][j]!='X')
            return;
        
        board[i][j] = '.';
        DFS(i+1,j,board);
        DFS(i-1,j,board);
        DFS(i,j+1,board);
        DFS(i,j-1,board);
    }
};
