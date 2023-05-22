class Solution {
    unordered_map<char,vector<pair<int,int>>> mp;
    int rows;
    int cols;
    bool dfs(int x, int y,vector<vector<char>>& board, string word, int index) {
        if(index == word.size())
        {
            return true;
        }
        if(min(x,y)<0 or x==rows or y==cols or board[x][y]!=word[index])
            return false;
        
        char temp = board[x][y];
        board[x][y] = '#';
        bool found = false;
        found = dfs(x+1,y,board,word,index+1) or dfs(x-1,y,board,word,index+1) or dfs(x,y+1,board,word,index+1) 
        or dfs(x,y-1,board,word,index+1);
        board[x][y] = temp;
        return found;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        for(auto str: words) {
            mp[str[0]];
        }
        this->rows = board.size();
        this->cols = board[0].size();
        for(int i=0;i<rows;++i) {
            for(int j=0;j<cols;++j) {
                if(mp.count(board[i][j]))
                {
                    mp[board[i][j]].push_back({i,j});
                }
            }
        }

        for(auto str:words)
        {
            for(auto &[x,y]: mp[str[0]]) {
                if(dfs(x,y,board,str,0))
                {
                    res.push_back(str);
                    break;
                }
                
            }
        }

        return res;
    }
};
