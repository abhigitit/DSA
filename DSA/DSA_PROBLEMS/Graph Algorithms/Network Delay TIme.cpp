/*

Leetcode: 743

Intuiton : Apply Dijkstra's algorithm to find out minimum time to reach the farthest node.
A simple BFS solution.

TC: O(V+E)
*/


class Solution {
public:
   
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
         unordered_map<int,vector<pair<int,int>>> adj;
     queue<pair<int,int>> BFS;
    vector<int> distances(n+1,INT_MAX);
 
        for(int i=0;i<times.size();++i)
        {
            int v = times[i][0];
            int w = times[i][1];
            int wt = times[i][2];
            adj[v].push_back({w,wt});
        }
        BFS.push({k,0});
        distances[k] = 0;
        
        while(!BFS.empty())
        {
            pair<int,int> curr = BFS.front();
            BFS.pop(); 
            int curr_node = curr.first;
            int curr_dist = curr.second;
           
            for(auto it:adj[curr_node])
            {
               
                int next_node = (it).first;
                int next_dist = (it).second;
                if(distances[next_node]>curr_dist+next_dist)
                {
                    BFS.push({next_node,next_dist+curr_dist});
                    distances[next_node] = curr_dist+next_dist;
                    
                } 
                
               
            }
        }
        int res = 0;
        for(int i=1;i<distances.size();++i)
        {
            if(distances[i]==INT_MAX)
                return -1;
            else
                res = max(res,distances[i]);
        }
        return res;
        
    }
};
