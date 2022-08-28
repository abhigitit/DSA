
/*
Leetcode : 828 - Count Unique Characters of All Substrings of a Given String

Intuition : https://www.youtube.com/watch?v=JT1NDR-M_8A&ab_channel=TECHDOSE

*/

class Solution {
public:
    int uniqueLetterString(string s) {
        map<char,vector<int>> store;
        int res = 0;
        for(auto i:s)
        {
            store[i].push_back(-1);
        }
       
         for(int i=0;i<s.size();++i)
        {
            store[s[i]].push_back(i);
        }
        
          for(int i=0;i<s.size();++i)
        {
            store[s[i]].push_back(s.size());
        }
        
        for(auto c:store)
        {
            for(int i=0;i<store[c.first].size()-2;++i)
            {
                int x = store[c.first][i];
                int y = store[c.first][i+1];
                int z = store[c.first][i+2];
                res+= (y-x)*(z-y);
            }
        }
        return res;
    }
};
