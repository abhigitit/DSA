/*
Leetcode : Break Palindrome

Intuition:For odd length palindrome, there is no use if we change middle character. Hence, ignore it.
For all other characters, we check if we can change the earliest occurring one to a and return the string.
If that does not happen, it means that the string contains all a's. So we change the last character to b.
TC:O(N)

*/

class Solution {
public:
    string breakPalindrome(string palindrome) {
        
        int n = palindrome.size();
        if(n==1) return "";
        for(int i=0;i<n;++i)
        {
            int j = n-1-i;
            if(i==j)
                continue;
            if(palindrome[i]!='a')
            {
               palindrome[i]='a';
                return palindrome;
            }
                
                
        }
            palindrome[n-1]='b';
        return palindrome;
    }
};
