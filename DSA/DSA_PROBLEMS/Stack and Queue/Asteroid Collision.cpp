/*
Leetcode: 735

Nick White

*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
       stack<int> st;
        vector<int> res;
        for(auto i:asteroids)
        {
            if(st.empty() or i>0)
                st.push(i);
            else{
                while(1)
                {
                    int peek = st.top();
                    if(peek<0)
                    {
                        st.push(i);
                        break;
                    }
                    else if(peek==-i)
                    {
                        st.pop();
                        break;
                    }
                    else if(peek>-i)
                        break;
                    else
                    {
                        st.pop();
                        if(st.empty())
                        {
                            st.push(i);
                            break;
                        }
                            
                    }
                }
            }
        }
        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
};
