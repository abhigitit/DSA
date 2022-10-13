/*
Count Vowels Permutation

https://www.youtube.com/watch?v=VUVpTZVa7Ls&t=358s&ab_channel=NeetCode

Intuition : DP
If length of the string is 1, how many strings end with a,e,i,o,u
a-1
e-1
i-1
o-1
u-1

If the length of the string is 2,how many strings end with a,e,i,o,u
How many end with 'a' is equal to how many vowel charcaters can be followed by 'a'. By the rules, its 3
Number of string ending with e + Number of string ending with u + Number of string ending with i = Number of string ending with 'a'
By the rules, construct the dp table
O(N)

*/

class Solution {
public:
    int countVowelPermutation(int n) {
        map<long,vector<long>> dp;
        long mod = pow(10, 9)+7;
        //a=0,e=1,i=2,o=3,u=4
        for(int i=0;i<n+1;++i)
        dp[i] = {0,0,0,0,0};
        dp[1] = {1,1,1,1,1};
        for(int j=2;j<n+1;++j)
        {
            dp[j][0] = dp[j-1][1] + dp[j-1][2] + dp[j-1][4];
            dp[j][1] = dp[j-1][0] + dp[j-1][2];
            dp[j][2] = dp[j-1][1] + dp[j-1][3];
            dp[j][3] = dp[j-1][2];
            dp[j][4] = dp[j-1][1] + dp[j-1][2];
        }
        
        long sum = accumulate(dp[n].begin(), dp[n].end(), 0);
        
        return sum % mod;
    }
};
