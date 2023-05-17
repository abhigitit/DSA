/*
https://www.youtube.com/watch?v=1BJJvodXiUY
*/

class Solution {
    vector<vector<int>> dir = {{0,1},{0-1},{1,0},{-1,0},{1,1},{1,-1},{-1,-1},{-1,1}};
    bool isValid(int x,int y,int rows,int cols)
    {
        return x>=0 and y>=0 and x<rows and y<cols;
    }
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int rows = board.size();
        int cols = board[0].size();
        int x = click[0];
        int y = click[1];
        if(board[x][y]=='M' or board[x][y]=='X')
        {
            board[x][y]='X';
            return board;
        }
        int num=0;
        for(auto d : dir)
        {
            int new_x = x+d[0];
            int new_y = y+d[1];
            if(isValid(new_x,new_y,rows,cols) and board[new_x][new_y]=='M')
            {
               num++;
            }
        }
        if(num)
        {
            board[x][y]=num+'0';
            return board;
        }

        board[x][y] = 'B';
        for(auto d : dir)
        {
            int new_x = x+d[0];
            int new_y = y+d[1];
            if(isValid(new_x,new_y,rows,cols) and board[new_x][new_y]=='E')
            {
                vector<int> temp = {new_x,new_y};
               updateBoard(board,temp);
            }
        }

return board;

    }
};
