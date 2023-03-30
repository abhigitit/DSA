/*
Find the Index of the First Occurrence in a String
Leetcode 28

*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        
        map<char,vector<int>> cache;
        
        for(int i=0;i<haystack.size();++i)
        {
            cache[haystack[i]].push_back(i);
        }
        bool flag;
        for(int i=0;i<cache[needle[0]].size();++i)
        {
            flag = 0;
            helper(needle,cache[needle[0]][i],haystack,flag);
            if(flag)
                return cache[needle[0]][i];
        }
        return -1;
    }
    
    void helper(string& needle, int i, string& haystack, bool& flag)
    {
        int j=0;
        while(j<needle.size() and i<haystack.size())
        {
            if(needle[j]!=haystack[i])
                break;
            i++;
            j++;
        }
        if(j==needle.size())
            flag=1;
    }
};
