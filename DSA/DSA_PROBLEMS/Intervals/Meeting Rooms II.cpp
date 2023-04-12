/*
 Meeting Rooms II
 */
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int,int> store;
        for(int i=0;i<intervals.size();++i)
        {
            int start = intervals[i][0];
            int end = intervals[i][1];
            store[start]++;
            store[end]--;
        }
        
        int count = 0;
        int res = INT_MIN;
        for(auto it:store)
        {
            count+=it.second;
            res = max(res,count);
        }
        return res;
    }
};
