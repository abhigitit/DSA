/*
1466 Reorder Routes to Make All Paths Lead to the City Zero

Intuition : For city 0, does your neighbors have an edge towards you? Else, increment count. Then check similarly for every node so that
all are redirected to 0.

Create neighbors adjacency list and edges adjacency list.
neighbors adjacency list = to traverse the neighbors
edges adjacency list = to check the direction of edge

*/

class Solution {
public:
set<pair<int,int>> hasEdge;
set<int> visited;
map<int,vector<int>> adj;
int count = 0;
    int minReorder(int n, vector<vector<int>>& connections) {
        for(int i=0;i<connections.size();++i)
        {
            hasEdge.insert({connections[i][0],connections[i][1]});
        }

        for(int i=0;i<connections.size();++i)
        {
            int v = connections[i][0];
            int w = connections[i][1];
            adj[v].push_back(w);
            adj[w].push_back(v);
        }
        visited.insert(0);
        dfs(0);
        return count;
    }

    void dfs(int city)
    {
        for(auto neighbor:adj[city])
        {
            if(!visited.count(neighbor))
            {
                if(!hasEdge.count({neighbor,city}))
                    count++;
                visited.insert(neighbor);
                dfs(neighbor);
            }
        }
    }
};
