
/*
Articulation Points : A vertex is called an articulation point if rmeoving it and all edges associated with it, the number of
connected components in the graph increases.

Biconnectivity : A connected undirected graph is binconnected if there are no vertices whose removal disconnects the rest of the graph.
Applications : to find critical points or single point of failures.

Brute Force : Remove each vertex and perform DFS or BFS on rest of the graph and check if its connected.
TC : O(V*(V+E))


Better Algoritm: Tarjan's Algoritm
 1)Prepare DFS spanning tree.
 2)Mention discovery time d of each vertex in order of DFS traversal
 3)Mention low time L of each vertex which is the earliest ancestor current node can reach from it's child path. (Ancestor can be the direct parent also;
 Once an ancestor is reached, no taking another edge to another ancestor)
 4)u is parent and v is child; if L[v]>=d[u], then u is an articulation point.[this does not hold true for root node]
 
 The intuition here is, before discovering the "could be articulation node" at x time in the DFS spanning tree, we will have few nodes discovered with discovery time less than x.
 If the child of "could be articulation node" has a backedge to an early ancestor whose discovery time is less than x, then the child of "could be articulation node" is given a low time y.
y<x..

So it means that if L[child] "y" < d[parent/ "could be articulation node"] "x" , then it means that even if could be articulation node is not present, we have this child
linked with the ancestor of "could be articulation node". Hence the "could be articulation node" is not articulation. If this condition fails and 
L[child] "y" >= d[parent/ "could be articulation node"] "x", then "could be articulation node" is an articulation point.
 
 
 TC: O(V+E)

https://www.youtube.com/watch?v=qNVNoZJFp_g&list=PLFj4kIJmwGu3m30HfYDDufr3PZBfyngr0&index=10&ab_channel=FitCoder

*/

#include <bits/stdc++.h>
using namespace std;
class Graph {
    map<int,vector<int>> adj;
    map<int,int> parent;
    vector<int> disc;
     vector<int> low;
    vector<int> res;
    vector<bool> visited;
    int time;
    int n;
    public:
    
    Graph(int V)
    {
        n = V;
        disc.resize(n,0);
        low.resize(n,0);
        visited.resize(n,false);
        time = 0;
    }
    
    void add_edge(int v,int w)
    {
        adj[v].push_back(w);
        adj[w].push_back(v);
        parent[v]=-1;
        parent[w]=-1;
    }
   vector<int> criticalConnections() {
  
        find_critical_connection(0);
    
        return res;
    }
    
    void find_critical_connection(int v)
    {
        visited[v]=true;
        disc[v]=time++;
        low[v]=disc[v];
        int child = 0;
        for(auto av:adj[v])
        {
            if(!visited[av])
            {
                child++;
                parent[av]=v;
                find_critical_connection(av);
                low[v]=min(low[v],low[av]);
                if(parent[v]==-1 and child>1)
                    res.push_back(v);
                
                if(parent[v]!=-1 and low[av]>=disc[v])
                 res.push_back(v);
            }
            else if(av != parent[v]) // Back edge; reached else if because its already discovered node but not a parent of current node, that means ancestor.
                low[v]=min(low[v],disc[av]);
        }
    }
    
};

int main()
{
    Graph g(6);
    g.add_edge(0,1);
    g.add_edge(1,2);
    g.add_edge(2,0);
    g.add_edge(1,3);
    g.add_edge(3,4);
    g.add_edge(4,5);
    g.add_edge(5,3);
  
vector<int> res = g.criticalConnections();
for(auto i:res)
{
    cout<<i<<endl;
}
    return 0;
}




