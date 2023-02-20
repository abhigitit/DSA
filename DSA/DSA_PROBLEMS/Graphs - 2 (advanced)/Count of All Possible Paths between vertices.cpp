
/*

Count all possible paths between source and destination.
Intuition : We need to reach the destination from the current vertex. To reach the destination, we need to perform dfs on all the adjacent nodes of the current to check if we would reach the destination. Change the source everytime and call the dfs. Once the source equals destination that means we have reached the destination, increase the variable count.

For all the adjacent nodes, i.e. nodes that are accessible from the current node, call the recursive function with the index of the adjacent node and the destination.


TC:O(V+E)
SC:O(V+E)

*/


#include<bits/stdc++.h>
using namespace std;


class Graph{
    int v;
    vector<list<int>> adj;
    vector<bool> visited;
    
    public:
    Graph(int v);
    void addEdge(int v, int w);
    void DFS(int s, int d, int& paths);
    int count_of_poaths(int s,int d);
};

Graph::Graph(int v)
{
    this->v = v;
    adj.resize(v);
    visited.resize(v,false);
};

void Graph::addEdge(int v,int w)
{
    adj[v].push_back(w);
};

void Graph::DFS(int s,int d, int& paths)
{
    visited[s]=1;
    if(s==d) paths++;
    else
    {
        list<int>::const_iterator it;
        for(it=adj[s].begin();it!=adj[s].end();++it)
        {
            if(!visited[*it])
            DFS(*it,d,paths);
        }
    }
    visited[s]=0;
};

int Graph::count_of_poaths(int s,int d)
{
    int paths = 0;
        DFS(s,d,paths);
    
    return paths;
    
};

int main()
{
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(1,3);
    g.addEdge(4,5);
    g.addEdge(0,3);
    g.addEdge(3,5);
    g.addEdge(0,2);
    cout<<g.count_of_poaths(0,5);
}

