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
      stack<pair<int,int>> mst;
       vector<int> res(temperatures.size(),0);
        for(int i=0;i<temperatures.size();++i)
        {
            
            while(!mst.empty() and temperatures[i]>mst.top().first)
            {
                res[mst.top().second] = i- mst.top().second;
                mst.pop();
            }
            
            mst.push({temperatures[i],i});
        }
        
        while(!mst.empty())
        {
            res[mst.top().second] = 0;
            mst.pop();
        }
        return res;
    }
};
