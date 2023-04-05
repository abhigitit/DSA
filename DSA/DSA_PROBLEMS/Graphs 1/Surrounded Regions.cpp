/*
Surrounded Regions
*/
class Solution {
public:
int rows;
int cols;
    void solve(vector<vector<char>>& board) {
        rows = board.size();
        cols = board[0].size();

        for(int i=0;i<rows;++i)
        {
            for(int j=0;j<cols;++j)
            {
                if((i==0 or j==0 or i==rows-1 or j==cols-1) and board[i][j]=='O')
                {
                    dfs(i,j,board);
                }
            }
        }

         for(int i=0;i<rows;++i)
        {
            for(int j=0;j<cols;++j)
            {
                if(board[i][j]=='O')
                {
                    board[i][j]='X';
                }
                else if(board[i][j]=='*')
                    board[i][j]='O';
            }
        }
    }

    void dfs(int i,int j, vector<vector<char>>& board)
    {
        if(min(i,j)<0 or i==rows or j==cols or board[i][j]!='O')
            return;
        board[i][j] = '*';
        dfs(i+1,j,board);
        dfs(i-1,j,board);
        dfs(i,j+1,board);
        dfs(i,j-1,board);
    }
};
