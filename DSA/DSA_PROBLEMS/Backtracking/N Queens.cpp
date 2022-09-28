/*
N Queens
51

https://www.youtube.com/watch?v=Ph95IHmRp5M&ab_channel=NeetCode

*/

class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> board;
    unordered_set<int> cols;
    unordered_set<int> posDiag;
    unordered_set<int> negDiag;
    vector<vector<string>> solveNQueens(int n) {
        board.resize(n,vector<string>(n,"."));
        backtrack(0,n);
        return res;
    }
    
    void backtrack(int r,int& n)
    {
        if(r==n)
        {
            vector<string> temp_res;
           for(int i=0;i<n;++i)
           {
               string temp="";
             for(int j=0;j<n;++j)  
             {
                 temp+=board[i][j];
             }
               temp_res.push_back(temp);
           }
            res.push_back(temp_res);
        }
        
        for(int c=0;c<n;++c)
        {
            if(cols.count(c) || posDiag.count(r+c) || negDiag.count(r-c))
                continue;
            
            cols.insert(c);
            posDiag.insert(r+c);
            negDiag.insert(r-c);
            board[r][c] = "Q";
            
            backtrack(r+1,n);
            
            cols.erase(c);
            posDiag.erase(r+c);
            negDiag.erase(r-c);
            board[r][c] = ".";
            
        }
    }
};
