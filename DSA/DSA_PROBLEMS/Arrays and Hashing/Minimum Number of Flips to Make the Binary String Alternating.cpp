
/*

Minimum Number of Flips to Make the Binary String Alternating

https://www.youtube.com/watch?v=MOeuK6gaC2A&ab_channel=NeetCode

*/

class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        s = s+s;
       string alt1="";
        string alt2="";
        
        for(int i=0;i<n;++i)
        {
            alt1+= i%2 ? '0':'1';
            alt2+= i%2 ? '1':'0';
        }
       
        int left = 0;
        int res = INT_MAX;
        int diff1 = 0;
        int diff2 =0;
        for(int right=0;right<s.size();++right)
        {
            if(s[right]!=alt1[right])
                diff1++;
            if(s[right]!=alt2[right])
                diff2++;
            
            if(right-left+1 > n)
            {
                if(s[left]!=alt1[left])
                    diff1--;
                if(s[left]!=alt2[left])
                    diff2--;
                left++;
            }
            if(right-left+1 == n)
            res = min(res,min(diff1,diff2));
        }
    return res;
    }
};
