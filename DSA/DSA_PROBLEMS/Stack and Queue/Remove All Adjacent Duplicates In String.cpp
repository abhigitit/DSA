/*
Leetcode: Remove All Adjacent Duplicates In String

Intuition : use a stack. if top of stack and current element are same, pop from stack and dont add current element.
add an initial character into stack so that we dont try to pop from empty stack.

*/
class Solution {
public:
   string removeDuplicates(string s) {
        if(s.size()==1) return s;
        stack<char> st;
        st.push('$');
        st.push(s[0]);
        for(int i=1;i<s.size();++i)
        {
            if(st.top()==s[i] and st.top()!='$')
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
        res.pop_back();
        reverse(res.begin(),res.end());
        return res;
    }
};
