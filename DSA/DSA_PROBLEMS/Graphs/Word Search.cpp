/*
Leetcode: Word Search

*/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i=0;i<board.size();++i)
        {
            for(int j=0;j<board[i].size();++j)
            {
                if(board[i][j]==word[0] and DFS(i,j,board,word,0))
                    return true;
            }
        }
        return false;
    }
    
    bool DFS(int i,int j,vector<vector<char>>& board,string word, int index)
    {
        if(index==word.size())
            return true;
        
        if(i<0 or j<0 or i>=board.size() or j>=board[i].size() or board[i][j]!=word[index])
            return false;

        
        char temp = board[i][j];
        board[i][j] = '*';
        
        bool found = DFS(i+1,j,board,word,index+1) || DFS(i-1,j,board,word,index+1) || DFS(i,j+1,board,word,index+1) || DFS(i,j-1,board,word,index+1);

        board[i][j]=temp;
        return found;
    }
};
