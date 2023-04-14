/*
Number of Visible People in a Queue

Monotonic decreasing stack from backside.
*/

class Solution {
  stack<int> mono;

public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
      int n = heights.size();
      vector<int> res(n);
      mono.push(heights[n-1]);
      for(int i=n-2;i>=0;--i)
      {
        int cnt = 0;
        while(!mono.empty() and heights[i]>mono.top())
        {
          cnt++;
          mono.pop();
        }
        if(!mono.empty()) cnt++;
        mono.push(heights[i]);
        res[i]=cnt;
      }
      return res;

    }
};
