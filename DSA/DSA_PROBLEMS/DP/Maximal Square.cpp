/*
https://www.youtube.com/watch?v=nZAyRZC8tko
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> temp(rows,vector<int>(cols,0));
        int ans = 0;

        for(int i=0;i<rows;++i) {
            temp[i][0]=matrix[i][0]-'0';
            ans = max(ans, temp[i][0]);
        }

        for(int j=0;j<cols;++j) {
            temp[0][j]=matrix[0][j]-'0';
            ans = max(ans, temp[0][j]);
        }

        for(int i=1;i<rows;++i) {
            for(int j=1;j<cols;++j) {
                if(matrix[i][j] == '1') {
                    temp[i][j] = 1 + min({temp[i-1][j-1],temp[i-1][j],temp[i][j-1]});
                    ans = max(ans,temp[i][j]);
                }
            }
        }

        return ans*ans;
    }
};
