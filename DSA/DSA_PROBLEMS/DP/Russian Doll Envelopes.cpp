
/*
 Russian Doll Envelopes
 354
 
 Similar to Longest Icreasing Subsequence
 
 */




class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector<int> dp(envelopes.size(),1);
        sort(envelopes.begin(),envelopes.end());
        for(int i=envelopes.size()-2;i>=0;--i)
        {
            for(int j=i;j<envelopes.size();++j)
            {
                 int nh = envelopes[j][0];
            int nw = envelopes[j][1];
            int h = envelopes[i][0];
            int w = envelopes[i][1];
            if(h<nh and w<nw)
                dp[i] = max(dp[i],1+dp[j]);
            }
           
        }
        
        return *max_element(dp.begin(),dp.end());
    }
};
