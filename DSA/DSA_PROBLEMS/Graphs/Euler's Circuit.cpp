/*

https://www.youtube.com/watch?v=WY6Jsp3NxIk&t=9s&ab_channel=TECHDOSE
Walk : Any random travsersal in the graph where the vertices and edges can repeat in the path is called a walk in graph.
Trail : A travsersal which does not involve the same edge in the path is called a trail.
Euler's Circuit: A trail which starts and ends at the same vertex is called euler's circuit. Such a graph is called Euler Graph.

1)Starting and ending nodes must be the same,
2)All the edges have to be explored, (can have seperate nodes without any edges as components, its fine; but if there is any edge in the graph thats not visited,
graph is not euler graph)
3)Already explored edge cannot be reconsidered.

Insight : All the nodes must have even degree. (degree is the no of edges associated with the node)
A graph with no edge is a euler graph.

Semi Eulerian graph:
1) All the edges have to be explored without repetetion (this is called euler path)
2) Starting and ending nodes must not be the same
 Insight : Exactly two verices must have odd degree(start and end vertex)

Intution:
First check : In multi component graph, all the edges must be part of single component and other component vertices must have 0 degree. This is how
all the edges can be traversed when DFS in applied in one component and can be called eulerian graph.

Second check : Degree of all nodes. 
The "could be eluerian component" must have 0 odd degree nodes to become eulerian graph.
if count of odd degree nodes = 2, then semi eulerian graph,
if count of odd degree nodes > 2, then not eulerian graph,
*/

#include <bits/stdc++.h>
using namespace std;

class Graph{
    map<int,vector<int>> adj;
    vector<bool> visited;
    int V;
    public:
    Graph(int V);
    void addEdge(int v, int w);
    void DFS(int s);
    bool isConnected();
    int find_euler();
    void is_euler();
};
Graph::Graph(int V)
{
    this->V = V;
    visited.resize(V,false);
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::DFS(int s)
{
   visited[s] = true;
   for(auto i:adj[s])
   {
       if(!visited[i])
       DFS(i);
   }
}

bool Graph::isConnected()
{
 int node = -1;
 for(int i=0;i<V;++i)
 {
     if(adj[i].size()>0) //find a node with edges
     {
         node = i;
         break;
     }
 }
 if(node==-1) return true;
 DFS(node); //apply dfs on the node with edges
 
 for(int i=0;i<V;++i)
 {
     if(!visited[i] and adj[i].size()>0) //after dfs is perfomed and still there exists a node which is not visited and has edges, it implies there is another component with edges. cannot be eulerian
       
     {
         return false;
     }
 }
 return true;
}


int Graph::find_euler()
{
   if(!isConnected())
   return 0;
   
   int odd = 0;
   for(int i=0;i<V;++i)
   {
      if(adj[i].size()&1) //check adj list size to find degree; &1 will give 1 if size is odd.
      odd++;
   }
   if(odd>2) // Not Eulerian
   return 0;
   
   return odd==0?2:1; // if odd == 0, Eulerian else odd will be 2 and semi eulerian
   
}

void Graph::is_euler()
{
   int res = find_euler();
   if(res==0)
   cout<<"Graph is not Euler Graph";
   else if(res==1)
   cout<<"Graph is semi Euler Graph";
   else
   cout<<"Graph is Euler Graph";
   
}
int main()
{
    Graph g(4);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(1,3);
   g.addEdge(0,1);
    g.is_euler();

    return 0;
}

