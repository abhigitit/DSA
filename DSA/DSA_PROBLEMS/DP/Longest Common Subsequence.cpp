/*

Longest Common Subsequence

https://www.youtube.com/watch?v=Ua0GhsJSlWM&t=821s&ab_channel=NeetCode

*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> LCS(text1.size()+1,vector<int>(text2.size()+1,0));
        
        int rows = text1.size() + 1;
        int cols = text2.size() + 1;
        
        for(int i=rows-2;i>=0;--i)
        {
            for(int j=cols-2;j>=0;--j)
            {
                if(text1[i]==text2[j])
                    LCS[i][j] = 1 + LCS[i+1][j+1];
                else
                    LCS[i][j] = max(LCS[i+1][j],LCS[i][j+1]);
            }
        }
        
        return LCS[0][0];
    }
};
