/*

Design Tic-Tac-Toe

Intuition : Give player one number 1 and player two number -1. Keep adding their moves to rows, cols diagonals using map and variables.

If the absolute value equals size, return winner.

O(N)

*/

class TicTacToe {
public:
  
    map<int,int> rows;
    map<int,int> cols;
    int D;
    int antiD;
    int n;
    TicTacToe(int n) {
        this->n = n;
        D=0;
        antiD=0;
    }
    
    int move(int row, int col, int player) {
      int curr_player = player==1 ? 1:-1;
        rows[row]+=curr_player;
        cols[col]+=curr_player;
        
        if(row==col) D+=curr_player;
        if(row+col==n-1) antiD+=curr_player;
        
        if(abs(rows[row])==n or abs(cols[col])==n or abs(D)==n or abs(antiD)==n)
            return player;
        
        return 0;
    }
};
