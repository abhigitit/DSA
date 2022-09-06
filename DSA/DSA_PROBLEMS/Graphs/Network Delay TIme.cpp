/*

Leetcode: 743

Intuiton : Aply Dijkstra's algorithm to find out minimum time to reach the farthest node.
A simple BFS solution.

TC: O(V+E)
*/


class Solution {
public:
    unordered_map<int,pair<int,int>> adj;
     queue<pair<int,int>> BFS;
    vector<int> distances;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        distances.resize(n+1,INT_MAX);
       
        for(int i=0;i<times.size();++i)
        {
            int v = times[i][0];
            int w = times[i][1];
            int wt = times[i][2];
            adj[v] = make_pair(w,wt);
            adj[w] = make_pair(v,wt);
        }
        BFS.push({n,0});
        distacnes[n] = 0;
        
        while(!BFS.empty())
        {
            pair<int,int> curr = BFS.top();
            BFS.pop();
            int curr_node = curr.first;
            int curr_dist = curr.second;
            pair<int,int>::const_iterator it;
            for(it=adj[curr_node].begin();it!=adj[curr_node].end();++it)
            {
                int next_node = (*it).first;
                int next_dist = (*it).second;
                if(distance[next_node]>curr_dist+next_dist)
                {
                    distance[next_node] = curr_dist+next_dist;
                    BFS.push({next_node,next_dist});
                }
            }
        }
        int res = 0;
        for(int i=0;i<distances.size();++i)
        {
            if(distances[i]==INT_MAX)
                return -1;
            else
                res = max(res,distances[i]);
        }
        return res;
        
    }
};
