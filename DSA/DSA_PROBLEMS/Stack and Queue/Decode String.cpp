/*
Decode String
*/
class Solution {
    stack<char> st;
    void helper(string num, string temp)
    {
        reverse(temp.begin(),temp.end());
        reverse(num.begin(),num.end());
        int n = stoi(num);
        for(int i=0;i<n;++i)
        {
            for(auto j:temp)
            {
                st.push(j);
            }
        }
    }
public:
    string decodeString(string s) {
        

        for(int i=0;i<s.size();++i)
        {
             if(s[i]!=']')
                st.push(s[i]);
            else
            {
                string temp="";
                while(!st.empty() and s[i]==']' and !isdigit(st.top()))
                {
                 if(st.top()!='[')
                        temp+=st.top();
                    st.pop();
                 }
            
                string num;
                while(!st.empty() and isdigit(st.top()))
                {
                    num+=st.top();
                    st.pop();
                }
                helper(num,temp);
            }

        }

        string res;
        while(!st.empty())
        {
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
