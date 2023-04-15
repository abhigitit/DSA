/*
Partition Labels

We only need the last index where every char appears in the string. And we should stretch the size of 
window until the very last index (could be of any element in our window). Once index reaches end, we can
say we can have partition.

*/
class Solution {
    map<char,int> lastIdx;
public:
    vector<int> partitionLabels(string s) {
        vector<int> res;
        for(int i=0;i<s.size();++i)
        {
            lastIdx[s[i]] = i;
        }

        int end = lastIdx[s[0]];
        int sze = 0;
        for(int i=0;i<s.size();++i)
        {
            sze++;
            end = max(end,lastIdx[s[i]]);
            if(i==end)
            {
                res.push_back(sze);
                sze = 0;
            }      
        }
        return res;

    }
};
