/*
 Number of Connected Components in an Undirected Graph
 
 */

class Solution {
public:
    map<int,vector<int>> adj;
    set<int> visited;
    int countComponents(int n, vector<vector<int>>& edges) {
        
        for(int i=0;i<edges.size();++i)
        {
            int v = edges[i][0];
            int w = edges[i][1];
            adj[v].push_back(w);
            adj[w].push_back(v);
        }
        int res=0;
        for(int i=0;i<n;++i)
        {
            if(!adj.count(i))
                res++; // count the nodes that are not in adj map because they are not connected to any edge
        }
        for(int i=0;i<n;++i)
        {
            for(auto m:adj[i])
            {
                if(!visited.count(m))
                {
                    DFS(m);
                    res++;
                } 
            } 
        }
       return res;
        
    }
    
    void DFS(int s)
    {
        visited.insert(s);
        for(auto m:adj[s])
        {
            if(!visited.count(m))
                     DFS(m);
        }
    }
};
