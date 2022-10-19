/*
Daily Temperatures

Intuition : Monotonic Decreasing Stack
Find immediate greater value on the right.
When an immediate greater value on the right is found, the value is popped. All the lesser values are popped.

O(N) STC

*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
      vector<int> res(temperatures.size(),0);
        
        stack<pair<int,int>> st;
        for(int i=0;i<temperatures.size();++i)
        {
            while(!st.empty() and temperatures[i]>st.top().first)
            {
                int prev_idx = st.top().second;
                st.pop();
                res[prev_idx] = i-prev_idx;
            }
            st.push({temperatures[i],i});
        }
        return res;
    }
};
