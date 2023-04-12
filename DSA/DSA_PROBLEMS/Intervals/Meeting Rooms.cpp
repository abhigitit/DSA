/*
Meeting Rooms
*/

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if(intervals.size()==0)
                return true;
        sort(intervals.begin(),intervals.end());
        
        for(int i=0;i<intervals.size()-1;++i)
        {
            int intr1_start = intervals[i][0];
            int intr1_end = intervals[i][1];
            int intr2_start = intervals[i+1][0];
            int intr2_end = intervals[i+1][0];
            
            if(intr1_start==intr2_start)
                return false;
            
            if(intr2_start<intr1_end)
                  return false;
        }
        return true;
    }
};
