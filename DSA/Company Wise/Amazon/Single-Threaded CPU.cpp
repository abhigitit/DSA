/*

Single-Threaded CPU

https://www.youtube.com/watch?v=RR1n-d4oYqE&ab_channel=NeetCode

*/

typedef pair<int,int> p;
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        for(int i=0;i<tasks.size();++i) tasks[i].push_back(i);
        sort(tasks.begin(),tasks.end());
        priority_queue<p, vector<p>, greater<p>> min_heap;
        vector<int> res;
        
        long long time=0;
        int i=0;
        while(!min_heap.empty() or i<tasks.size())
        {
            while(i<tasks.size() and time>=tasks[i][0])
            {
                min_heap.push({tasks[i][1],tasks[i][2]});
                i++;
            }
            
            if(min_heap.empty())
            {
               time = tasks[i][0]; 
            }
            else
            {
                p temp = min_heap.top();
                min_heap.pop();
                time+=temp.first;
                res.push_back(temp.second);
            }
        }

        return res;
    }
};
