/*
Isomorphic strings
https://www.youtube.com/watch?v=7yF-U1hLEqQ&ab_channel=NeetCode

*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        return helper(s,t) && helper(t,s);
    }
    
    bool helper(string s, string t)
    {
        map<char,char> cache;
        for(int i=0;i<s.size();++i)
        {
            if(cache.count(s[i]))
            {
                if(cache[s[i]]!=t[i]) return false;
            }
            else
                cache[s[i]]=t[i];
        }
        return true;
    }
};
