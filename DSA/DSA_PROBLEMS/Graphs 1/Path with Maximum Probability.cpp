/*
Path with Maximum Probability

1514

Dijkstras Algorithm; Max heap
*/

class Solution {
public:
unordered_map<int,double> shortest;
unordered_map<int,vector<pair<int,double>>> adj;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        for(int i=0;i<edges.size();++i)
        {
            int v = edges[i][0];
            int w = edges[i][1];

            double cost = succProb[i];

            adj[v].push_back({w,cost});
            adj[w].push_back({v,cost});
        }

        priority_queue<pair<double,int>> maxHeap;
        maxHeap.push({1,start});

        while(!maxHeap.empty() and shortest.size()!=adj.size())
        {
            auto curr_node_info = maxHeap.top();
            maxHeap.pop();
            
            double cost_till_curr = curr_node_info.first;
            int curr_node = curr_node_info.second;

            if(shortest.count(curr_node))
                continue;
            
            shortest[curr_node] = cost_till_curr;

            for(auto v:adj[curr_node])
            {
                int next_node = v.first;
                double cost_reach_next = v.second;
                if(!shortest.count(next_node))
                    maxHeap.push({(cost_till_curr*cost_reach_next),next_node});
  
            }


        }

        return shortest[end];
    }
};
