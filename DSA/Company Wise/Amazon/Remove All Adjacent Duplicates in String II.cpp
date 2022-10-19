/*
Leetcode: Remove All Adjacent Duplicates in String II

Intution: Use a stack of pair to maintain char and frequency.
If element to be inserted equals top of stack element, increment frequency,
else just make new entry.
If the top of stack char frequency matches k, pop.

*/

class Solution {
public:
    string removeDuplicates(string s, int k) {
        if(s.size()==1) return s;
        stack<pair<char,int>> st;
        for(int i=0;i<s.size();++i)
            
        {
            if(!st.empty() and s[i]==st.top().first)
            {
                st.top().second++;
            }
             else
                st.push(make_pair(s[i],1));
           
            if(st.top().second==k)
            {
                st.pop();
            }
            
           
        }
        string res="";
        while(!st.empty())
        {
            int n=st.top().second;
            while(n--)
            {
                 res+=st.top().first; 
            }
          
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
