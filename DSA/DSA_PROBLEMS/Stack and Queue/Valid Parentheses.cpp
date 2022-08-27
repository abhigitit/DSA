
/*
Leetcode : 20
*/


class Solution {
public:
    bool isValid(string s) {
        if(s.size()%2!=0) return false;
        stack<char> st;
        
        for(int i=0;i<s.size();++i)
        {
            if(!st.empty() and st.top() == '(' and s[i]==')')
                st.pop();
            else if(!st.empty() and st.top() == '{' and s[i]=='}')
                st.pop();
            else if(!st.empty() and st.top() == '[' and s[i]==']')
                st.pop();
            else
                st.push(s[i]);
        }
        return st.empty();
        
    }
};
