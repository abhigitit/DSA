/*
Longest Common Prefix
Take first string and compare rest with this 
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string longestCommonPrefix = "";
        if(strs.size()==0) return "";
        if(strs.size()==1) return strs[0];

        for(int i=0;i<strs[0].size();++i)
        {
            for(auto st:strs)
            {
                if(i==st.size() or strs[0][i]!=st[i])
                    return longestCommonPrefix; 
            }
            longestCommonPrefix+=strs[0][i];
        }


        return longestCommonPrefix;
    }
};
