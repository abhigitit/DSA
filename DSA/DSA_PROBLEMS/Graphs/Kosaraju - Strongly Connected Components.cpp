/*
https://www.youtube.com/watch?v=Rs6DXyWpWrI&t=591s&ab_channel=TECHDOSE
Kosaraju's Algoithm to find Strongly Connected Components in directed graph.

Strongly Connected Component : If we can reach from every vertex to every other vertx in a component of the graph, then the component 
is called SSC.

Single Node is always SSC.

The idea behind this algorithm:
Consider there are two SSCs in the graph : SSC1 and SSC2

There is one outgoing edge from SSC1 to SSC2 : SSC1--->SSC2

1)Apply DFS on one vertex on SSC1 and all the vertices of SSC1 are traversed because of SSC property and because of the outgoing edge from SSC1 to SSC2,
all vertices of SSC2 are also traversed all the vertices are pushed onto the stack so that the first vertex from SSC1 is on top of the stack.


2)Build trnaspose of the graph:
Transpose of the graph is a graph obtained from reversing direction of all the edges.
A SSC remains SSC after transposing the graph.

Now the components look like this... SSC1<---SSC2

3) Apply DFS on the elements from the stack using transposed graph.
After all the vertices are traversed in SSC1, as there is no outgoing edge from SSC1, DFS terminates. Print all the connected nodes in SSC1.

TC: O(3(V+E)) ==> 2 times DFS, 1 time transpose
*/

#include <bits/stdc++.h>
using namespace std;

class Graph{
    map<int,vector<int>> adj,rev;
    vector<bool> visited;
    stack<int> st;
    int V;
    public:
    Graph(int V);
    void addEdge(int v, int w);
    void DFS1(int s);
    void DFS2(int s);
    void transpose_graph();
    void find_SSC();
};
Graph::Graph(int V)
{
    this->V = V;
    visited.resize(V,false);
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::DFS1(int s)
{
    visited[s] = true;
    for(auto i:adj[s])
    {
        
            if(!visited[i])
            DFS1(i);
    
    }
    st.push(s);
}

void Graph::transpose_graph()
{
    for(int i=0;i<V;++i)
    {
        for(auto j:adj[i])
        rev[j].push_back(i);
    }
}

void Graph::DFS2(int s)
{
    cout<<s<<",";
    visited[s] = true;
      for(auto i:rev[s])
    {
        
            if(!visited[i])
            DFS2(i);
    
    }
    
}
void Graph::find_SSC()
{
    for(int i=0;i<V;++i)
    {
        if(!visited[i])
        DFS1(i);
    }
    transpose_graph();
    fill(visited.begin(),visited.end(),false);
    while(!st.empty())
    {
        int temp = st.top();
        st.pop();
        if(!visited[temp])
        {
            DFS2(temp);
            cout<<"\n";
        }
        
    }
}
int main()
{
    Graph g(8);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(5,7);
    g.addEdge(5,6);
    g.addEdge(6,4);
    g.addEdge(6,7);
    g.find_SSC();

    return 0;
}
