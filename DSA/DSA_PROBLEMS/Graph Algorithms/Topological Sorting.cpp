
/*
Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u v, vertex u comes before v in the ordering.
Topological Sorting for a graph is not possible if the graph is not a DAG.
*/


#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    vector<list<int>> adj;
    vector<bool> visited;
    stack<int> st;
    
    public:
    Graph(int V);
    void addEdge(int v,int w);
    void DFS(int s);
    void TS();
};

Graph::Graph(int V)
{
    this->V = V;
    adj.resize(V);
    visited.resize(V,false);
}

void Graph::addEdge(int v,int w)
{
    adj[v].push_back(w);
}

void Graph::DFS(int s)
{
    visited[s]=true;
    list<int>::const_iterator it;
    for(it=adj[s].begin();it!=adj[s].end();++it)
    {
        if(!visited[*it])
        DFS(*it);
    }
    st.push(s);
}
void Graph::TS()
{
   for(int i=0;i<this->V;++i){
       if(!visited[i])
       DFS(i);
   } 
   
   while(!st.empty())
   {
       cout<<st.top()<<endl;
       st.pop();
   }
   
}


int main()
{
    Graph g(5);
    g.addEdge(1,0);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(3,0);
    g.TS();
    
}
