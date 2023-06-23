class Solution {
public:

    int help(int i,vector<int>& piles,int M)
    {
        if(i>=piles.size()) {return 0;}
        int total=0;
        int ans = INT_MIN;
        for(int j=0;j<2*M;++j)
        {
            if(i+j<piles.size()){total+=piles[i+j];}
            ans = max(ans,total-help(i+j+1,piles,max(M,j+1)));
        }
        return ans;
    }
    int stoneGameII(vector<int>& piles) {
        int res2 = accumulate(piles.begin(),piles.end(),0);
       int res1 = help(0,piles,1);
       return (res1+res2)/2;
    }
};
