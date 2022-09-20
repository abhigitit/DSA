
/*
Amount of New Area Painted Each Day
leetcode: 2158

https://www.youtube.com/watch?v=cHYjuMPTHt4&ab_channel=CrackingFAANG
TC:O(N^2)
*/


class Solution {
public:
    vector<int> amountPainted(vector<vector<int>>& paint) {
      unordered_map<int,int> cache;
        vector<int> res;
        for(int i=0;i<paint.size();++i)
        {
            int start = paint[i][0];
            int end = paint[i][1];
            int work=0;
            while(start<end)
            {
                if(cache.find(start)!=cache.end())
                {
                    int prev_end = cache[start];
                    cache[start] = max(cache[start],end);
                    start = prev_end;
                }
                else
                {
                  cache[start]= end;
                    start++;
                    work++;
                }
            }
            
            res.push_back(work);
        }
        return res;
    }
};
