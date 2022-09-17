/*
 
 Longest Palindromic Substring.cpp
 AE
 */


class Solution {
public:
    string longestPalindrome(string s) {
      
        vector<int> answer{0,1};
        for(int i=0;i<s.size();++i)
        {
            vector<int> odd = palindrome(i-1,i+1,s);
            vector<int> even = palindrome(i,i+1,s);
            vector<int> Longest = odd[1]-odd[0]>even[1]-even[0] ? odd : even;
            answer = Longest[1]-Longest[0]>answer[1]-answer[0] ? Longest :answer;
        }
        
        return s.substr(answer[0],answer[1]-answer[0]);
    }
    
    vector<int> palindrome(int i,int j, string& s)
    {
        while(i>=0 and j<s.size())
        {
            if(s[i]!=s[j])
                break;
            i--;
            j++;
        }
        return {i+1,j};
    }
};
