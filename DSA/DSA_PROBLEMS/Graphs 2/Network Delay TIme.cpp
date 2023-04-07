/*

Leetcode: 743

Intuiton : Apply Dijkstra's algorithm to find out minimum time to reach the farthest node.
A simple BFS solution.

Solution is exact to algorithm code. If all nodes are node reachable i.e. at the end, if the hashmap shortest's size != no of nodes, return -1

TC: O(V+E)
*/


typedef pair<int,int> P;
class Solution {
public:
    unordered_map<int,vector<pair<int,int>>> adj;
    unordered_map<int,int> shortest;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<P, vector<P>, greater<P>> minHeap;

        for(int i=0;i<times.size();++i)
        {
            int v = times[i][0];
            int w = times[i][1];
            int cost = times[i][2];

            adj[v].push_back({w,cost});
        }

        minHeap.push({0,k});
        int res = 0;
        while(!minHeap.empty() and shortest.size()!=n)
        {
            
            auto curr_node_info = minHeap.top();
            minHeap.pop();
            
            int cost_till_curr = curr_node_info.first;
            int curr_node = curr_node_info.second;
            
            if(shortest.count(curr_node))
                continue;
                
            shortest[curr_node] = cost_till_curr;
            res = max(res,cost_till_curr);
            
            for(auto v: adj[curr_node])
            {
                int next_node = v.first;
                int cost_to_next = v.second;
                if(!shortest.count(next_node))
                    minHeap.push({(cost_to_next + cost_till_curr), next_node});
                    
            }
            
        }

        return shortest.size()==n ? res : -1;

    }
};
