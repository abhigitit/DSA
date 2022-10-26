/*
Longest String Chain

Intuition : Similar to Longest Increasing Subsequence but we need to implement a function to check the condition

https://www.youtube.com/watch?v=YY8iBaYcc4g&ab_channel=takeUforward

*/

bool compare(string& s1, string& s2)
{
    return s1.size()<s2.size();
}
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),compare);
        vector<int> dp(words.size(),1);
        
        for(int i=words.size()-2;i>=0;--i)
        {
            for(int j=i+1;j<words.size();++j)
            {
                if(chainCompare(words[i],words[j]))
                    dp[i] = max(dp[i],dp[j]+1);
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
    
    bool chainCompare(string& word1, string& word2)
    {
        if(word2.size()!=word1.size()+1)
            return false;
        int i=0;
        int j=0;
        while(j<word2.size())
        {
            if(word1[i]==word2[j])
            {
                i++;
                j++;
            }
            else
                j++;
        }
        if(i==word1.size() and j==word2.size())
            return true;
        return false;
    }
};
