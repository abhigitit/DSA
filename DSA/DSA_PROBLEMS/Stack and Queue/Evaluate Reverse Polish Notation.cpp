
/*
Leetocde: 150

Intution : Using stack

TC: O(N)
SC:O(N)

*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for(auto i:tokens)
        {
            if(i=="+")
            {
                int a = st.top();
                st.pop();
                int b= st.top();
                st.pop();
                st.push(a+b);
            }
            
             else if(i=="-")
            {
                int a = st.top();
                st.pop();
                int b= st.top();
                st.pop();
                st.push(b-a);
            }
              else if(i=="*")
            {
                int a = st.top();
                st.pop();
                int b= st.top();
                st.pop();
                st.push(b*a);
            }
               else if(i=="/")
            {
                int a = st.top();
                st.pop();
                int b= st.top();
                st.pop();
                st.push(floor(b/a));
            }
            else st.push(stoi(i));
        }
        return st.top();
    }
};
