/*
Leetcode: 1584

Its a classic Minimum Spanning Tree problem.
We use BFS approach to solve this.
We can start with any node and add all other nodes which are not part of connected components with their weights(distances) from current node into min heap.
We take greedy approach and eventually form the connection.


https://www.youtube.com/watch?v=f7JOBJIC-NA&ab_channel=NeetCode


TC: O(n^2logn)

n^2 comes from checking all other nodes while on one node and logn comes from min heap.

*/

class Solution {
public:
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> min_heap;
    vector<vector<pair<int,int>>> adj;
    unordered_set<int> visited;
    int minCostConnectPoints(vector<vector<int>>& points) {
        int res = 0;
        adj.resize(points.size());
 
           for(int i=0;i<points.size();++i)
            
        {
            int x1 = points[i][0];
            int y1 = points[i][1];
            
            for(int j=i+1;j<points.size();++j)
            {
              int x2 = points[j][0];
              int y2 = points[j][1];  
               int dist = abs(x2-x1) + abs(y2-y1);
                adj[i].push_back(make_pair(dist,j));
                adj[j].push_back(make_pair(dist,i));
            }
        }
        min_heap.push(make_pair(0,0));
        while(visited.size()<points.size())
        {
          pair<int,int> cost_and_node = min_heap.top();  
            min_heap.pop();
            int cost = cost_and_node.first;
            int node = cost_and_node.second;
            if(visited.find(node)!=visited.end())
                continue;
            res+=cost;
            visited.insert(node);
            for(auto nei:adj[node])
            {
                pair<int,int> next_vertex = nei;
                if(visited.find(next_vertex.second)==visited.end())
                    min_heap.push(make_pair(next_vertex.first,next_vertex.second));
            }
        }

        return res;
    }
};
