/*
Merge Intervals

https://www.youtube.com/watch?v=44H3cEC2fFM&ab_channel=NeetCode

Intuition : Sort and add first intervsl into the res. check from second and keep changing.

*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==1) return intervals;
        vector<vector<int>> res;
       sort(intervals.begin(),intervals.end());
        res.push_back(intervals[0]);
        for(int i=1;i<intervals.size();++i)
        {
            int last_end = res[res.size()-1][1];
            int curr_start = intervals[i][0];
            int curr_end = intervals[i][1];
            if(curr_start<=last_end)
                res[res.size()-1][1] = max(last_end,curr_end);
            else
                res.push_back(intervals[i]);
        }
        return res;
    }
};
