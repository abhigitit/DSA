/*
Leetcode : 759

Intuition : Use PQ and arrange schedules of employees based on start time.
Now if start time of second employee is greater than end time of first employee, then there is a free time between end(first emp) to start(second emp).
Update end time to max of end time(secnd emp,first emp).

TC:O(NlogN)
*/

class Solution {
    struct comparatorpq {
    bool operator()(Interval &s1, Interval &s2)
    {
        return s1.start > s2.start;
        }
    };
public:
    
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> res;
        priority_queue<Interval,vector<Interval>, comparatorpq> min_heap;
        
        for(auto& i:schedule)
        {
            for(auto& j:i)
            {
                min_heap.push(j);
            }
        }
        
        int end = min_heap.top().end;
        min_heap.pop();
        while(!min_heap.empty())
        {
           Interval temp =  min_heap.top();
             min_heap.pop();
            if(temp.start>end)
                res.push_back(Interval(end,temp.start));
            end = max(temp.end,end);
        }
        return res;
    }
};
