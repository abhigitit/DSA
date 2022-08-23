/*
Leetcode: Remove All Adjacent Duplicates In String

Intuition : use a stack. if top of stack and current element are same, pop from stack and dont add current element.
To not to pop from stack when its empty, add condition.


*/
class Solution {
public:
   string removeDuplicates(string s) {
        if(s.size()==1) return s;
        stack<char> st;
        for(int i=0;i<s.size();++i)
        {
            if(!st.empty() and st.top()==s[i])
            {
                st.pop();
            }
            else
            st.push(s[i]);
        }
        string res = "";
        while(!st.empty())
        {
            res+=st.top();
            st.pop();
            
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
