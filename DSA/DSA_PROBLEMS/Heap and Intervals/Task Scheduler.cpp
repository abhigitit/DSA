/*
PQ and a wait queue
*/
class Solution {
    priority_queue<int> pq;
    queue<pair<int,int>> waitq;
    map<char,int> freq;
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n==0)
            return tasks.size();
        
        for(auto i:tasks)
        {
            freq[i]++;
        }
        for(auto i:freq)
        {
            if(i.second!=0)
                pq.push(i.second);
        }

        int time = 0;
        while(!pq.empty() or !waitq.empty())
        {
            time++;
            if(!pq.empty())
            {
            int task = pq.top();
            pq.pop();
            task--;
            if(task>0)
                waitq.push({task,time+n});
            }
            if(!waitq.empty() and time==waitq.front().second)
            {
                pq.push(waitq.front().first);
                waitq.pop();
            }
            
            
        }
        return time;
    }
};
