/*

Longest Substring Without Repeating Characters

Intuition : AE
If we have already seen the character, make sure that the startidx is updated to position greater than last seen of the current character.

TC:O(N)

*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> cache;
        int len =0;
        int startidx =0;
        for(int i=0;i<s.size();++i)
        {
            if(cache.find(s[i])!=cache.end())
                startidx = max(startidx,cache[s[i]]+1);
            len = max(len,i+1-startidx);
            cache[s[i]]=i;
        }
        
        return len;
    }
};
