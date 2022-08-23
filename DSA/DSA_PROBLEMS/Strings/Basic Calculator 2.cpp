/*
leetcode 227
https://www.youtube.com/watch?v=W3Rg4HVSZ9k&ab_channel=CrackingFAANG

*/

class Solution {
public:
    int calculate(string s) {
        int i=0;
        int curr=0;
        int res=0,prev=0;
        char curr_operation = '+';
        char curr_char;
        while(i<s.size())
        {
            curr_char = s[i];
            if(isdigit(curr_char))
            {
                while(i<s.size() and isdigit(s[i]))
                {
                    curr = curr*10 + unsigned(s[i]-'0');
                    i++;
                }
                i--;
            if(curr_operation=='+')
            {
                res+=curr;
                prev = curr;
            }
            else if(curr_operation=='-')
            {
                res-= curr;
                prev = -curr;
            }
            else if(curr_operation=='*')
            {
                res-=prev;
                res+=curr*prev;
                prev = prev*curr;
            }
            
             else
            {
                res-=prev;
                res+= floor(prev/curr);
                prev = floor(prev/curr);
            }
                curr=0;
            }
            
            else if(curr_char!=' ')
                curr_operation = curr_char;
            i++;
            
        }
        return res;
    }
};
