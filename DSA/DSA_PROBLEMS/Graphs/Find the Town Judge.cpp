/*
Find the Town Judge

Intuition : A node has an outedge if its trusts another node. A node has in edge if it is trusted by other node.
if(outedges == 0 and inedges == n-1(except itself)) then he or she is the judge.

*/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        map<int,int> out;
        map<int,int> in;
        
        for(auto i:trust)
        {
            out[i[0]]++;
            in[i[1]]++;
        }
        
        for(int i=1;i<=n;++i)
        {
            if(out[i]==0 and in[i]==n-1)
                return i;
        }
        return -1;
    }
};
