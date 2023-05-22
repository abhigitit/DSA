/*
Word Break

Parition at those points that create a word present in dictionary.
https://www.youtube.com/watch?v=th4OnoGasMU



*/

class Solution {
    map<int,bool> dp;
    bool helper(string s,int idx,set<string>& st) {
        if(idx==s.size()) return true;
        if(dp.count(idx)) return dp[idx];
        for(int i=idx;i<s.size();++i) {
            if(st.count(s.substr(idx,i-idx+1)) and helper(s,i+1,st))
                return dp[idx]=true;
        }
        return dp[idx]=false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st(wordDict.begin(),wordDict.end());
        return helper(s,0,st);
    }
};


