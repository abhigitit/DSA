/*

Leetcode: 743

Intuiton : Apply Dijkstra's algorithm to find out minimum time to reach the farthest node.
A simple BFS solution.

Solution is exact to algorithm code. If all nodes are node reachable i.e. at the end, if the hashmap shortest's size != no of nodes, return -1

TC: O(V+E)
*/


typedef pair<int,int> P;
class Solution {
    unordered_map<int,vector<P>> adj;
    unordered_map<int,int> time;
    priority_queue<P,vector<P>, greater<P>> minheap;

public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        for(int i=0;i<times.size();++i)
        {
            int u = times[i][0];
            int v = times[i][1];
            int cost = times[i][2];
            adj[u].push_back({v,cost});
        }

    minheap.push({0,k});
    

    while(!minheap.empty() and time.size()!=n)
    {
        auto nodeInfo = minheap.top();
        minheap.pop();
        int node = nodeInfo.second;
        int timeNode = nodeInfo.first;

        if(time.count(node))
            continue;
        
        time[node] = timeNode;

        for(auto it:adj[node])
        {
            int nei = it.first;
            int timeNei = it.second;
            if(!time.count(nei))
            {
                minheap.push({timeNode+timeNei,nei});
            }
        }

    }


    int res = INT_MIN;

    for(auto it:time)
    {
        res = max(res,it.second);
    }

    return time.size()==n ? res : -1;
    
    }
};
