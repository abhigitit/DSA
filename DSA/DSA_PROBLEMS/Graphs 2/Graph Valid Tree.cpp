/*
Graph Valid Tree
A tree needs to be connected; no disconnected components.

A tree cannot  have loops

*/
class Solution {
    vector<vector<int>> adj;
    set<int> visited;
    bool isCyclcic(int node,int parent)
    {
        visited.insert(node);
        for(auto nei:adj[node])
        {
            if(!visited.count(nei))
            {
                if(isCyclcic(nei,node))
                    return true;
            }
            else if(nei!=parent)
            {
                return true;
            }
        }
        return false;
    }
    
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        int components = 0;
        for(int i=0;i<edges.size();++i)
        {
            int v = edges[i][0];
            int w = edges[i][1];
            adj[v].push_back(w);
            adj[w].push_back(v);
        }
        
        for(int i=0;i<n;++i)
        {
            if(!visited.count(i))
            {
                if(isCyclcic(i,-1))
                    return false;
                components++;
            }
               
        }
        
        return components==1;
    }
};
