/*
Merge Intervals
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end());
        res.push_back(intervals[0]);
        for(int i=1;i<intervals.size();++i)
        {

            int intr1_start = res[res.size()-1][0];
            int intr1_end = res[res.size()-1][1];
            int intr2_start = intervals[i][0];
            int intr2_end = intervals[i][1];

            if(intr2_start<=intr1_end)
            {
                res[res.size()-1][1] = max(intr1_end,intr2_end);
            }
            else
                res.push_back(intervals[i]);

        }

        return res;
    }
};
