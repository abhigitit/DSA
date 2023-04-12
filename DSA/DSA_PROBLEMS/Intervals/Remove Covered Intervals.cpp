/*
Remove Covered Intervals
*/

bool compare(vector<int> a, vector<int> b)
    {
        if(a[0]!=b[0])
            return a[0]<b[0];
        else
            return a[1]>b[1]; //[1,4], [1,2] because my logic is im trying to merge i+1 into i 
    }
class Solution {
   
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),compare);
        int prevStart = intervals[0][0];
        int prevEnd = intervals[0][1];
        int res = intervals.size();
        for(int i=1;i<intervals.size();++i)
        {
            int intr_start = intervals[i][0];
            int intr_end = intervals[i][1];

            if(intr_end<=prevEnd and intr_start>=prevStart)
            {
                res--;
            }
            else
            {
                prevStart = intr_start;
                prevEnd = intr_end;
            }

        }
        return res;
    }
};
