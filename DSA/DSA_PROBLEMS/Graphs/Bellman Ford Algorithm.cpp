/*

To find out single source shortest path to all other vertices.

Both Bellman FOrd and Dijkstra's algorithms fail when there are negative edge weight cycles in the graph. But bellman ford can detect negative edge weights.
Dijkstra's may or maynot give correct result.

Negative edge weight cycle: we start at a particular node and return back to the node. if the cost is negative, it means the graph has negative edge weight cycle.
eg: A->B, B->C, C->A : 2,3,-6. Cost from A to A is -1

In a positive edge, the cost to return back to the source is postive. 2,3,-3. In this case Bellman Ford will give right answer.
But it fails in the case of Negative edge weight cycle. However, Bellman Ford can detect negative edge weight cycle.

Idea behind Bellman Ford: Relax all the edges. How many times? n-1 times where n is the number of vertices and n-1 would be the max number of edges
from source to destination.

Why n-1 times? In the worst case, ordering of edges will be such that it takes n-1 times for all the edges to relax. Consider source to be first index and
destination to be last index. If there are n nodes, there could be n-1 edges to the destination in the longest path possible where all the other nodes come in between.
After every relaxation, one of the other n-1 nodes' distance can be updated and needs to be rechecked. SO perform n-1 relaxations so that all the updations happen.

https://www.youtube.com/watch?v=75yC1vbS8S8&ab_channel=takeUforward

Bellman ford algorithm is dynamic programming approach where we explore all the paths and decide which is optimal where as Dijkstras is a greedy algorithm.
What is relaxation?
Relaxation between pair of two vertices u,v : Check that current distance of u + cost of u->v < current distance of v, then change distance of v
d[v] = d[u] + cost(uv)

After performing n-1 relaxations, it is guranteed that the distance array is populated with correct shortest distances.
Then, as the final step, perform one more relaxation and validate if the distance array is changing. If its changing, then we detect a negative edge wt cycle.

https://www.youtube.com/watch?v=24HziTZ8_xo&t=9s&ab_channel=TECHDOSE
TC: O(VE)
*/

#include <bits/stdc++.h>

using namespace std;


class Graph
{
    int V;
    vector<vector<int>> edges;
    vector<int> parent;
    vector<int> cost;
    public:
    Graph(int V,int e)
    {
        edges.resize(e);
        parent.resize(V,0);
        parent[0] = -1;
        cost.resize(V,INT_MAX);
        cost[0] = 0;
        this->V = V;
    }
    
    void addEdge(int edge, int v,int w, int wt)
    {
        edges[edge].push_back(v);
        edges[edge].push_back(w);
        edges[edge].push_back(wt);
    }
    
    void Bellman()
    {
        bool updated;
        for(int i=0;i<V-1;++i)
        {
            updated = false;
            
            for(int j=0;j<edges.size();j++)
            {
                int u = edges[j][0];
                int v = edges[j][1];
                int wt = edges[j][2];
                
                if(cost[u]!=INT_MAX and cost[u]+wt < cost[v])
                {
  
                    cost[v] = cost[u]+wt;
                    parent[v] = u;
                    updated = true;
                }
            }
            if(!updated)
            break;
        }
        
         for(int j=0;j<edges.size() and updated==true;j++)
            {
                int u = edges[j][0];
                int v = edges[j][1];
                int wt = edges[j][2];
                
                if(cost[u]!=INT_MAX and cost[u]+wt < cost[v])
                {
                   cout<<"Negative Edge Wt cycle detected"<<endl;
                   break;
                }
            }
        
        if(!updated)
        {
            cout<<"Printing SPG"<<endl;
            for(int i=1;i<V;++i)
            {
                
               cout<<parent[i]<< "-->" <<i<<": "<<cost[i]<<endl; 
            }
        }
        
        
    }
    

};


int main()
{
    Graph g(5,10);
    g.addEdge(0,0,1,6);
    g.addEdge(1,0,2,7);
    g.addEdge(2,1,2,8);
    g.addEdge(3,2,3,9);
    g.addEdge(4,2,4,-3);
    g.addEdge(5,1,3,-4);
    g.addEdge(6,3,4,7);
    g.addEdge(7,1,4,5);
    g.addEdge(8,4,1,-2);
    g.addEdge(9,3,0,2);
    
g.Bellman();
    return 0;
}



