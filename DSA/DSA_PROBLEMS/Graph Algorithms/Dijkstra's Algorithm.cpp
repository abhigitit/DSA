/*
Dijkstra's Algorithm

Why? 
BFS is used to find the shortest path between vertices. However, a traditional BFS fails when there are weights associated with the edges.

What?
Dijkstra's Algorithm is a greedy algorithm. We have a frontier which is the set of visited nodes till now. Among that frontier nodes, we consider 
all the outgoing edges and choose the minimum weight path (total cost from the source).

MinHeap to store frontier nodes {cost,node}
A hashmap to store {node : minimum cost to the node}

Graph : A to B (10 cost), A to C (3 cost) , C to B (4 cost), C to D (2 cost)

Source A. 

1)Add {0,A} into minHeap.
2)Pop from minHeap and update minimum wt to A in hashmap as 0. {A : 0}
3)Push neighbors of A to minHeap {cost to reach B '10', B}, {cost to reach C '3', C}
4)Pop from minHeap and update minimum wt to C in hashmap as 0. {C : 3}\
5)Push neighbors of C to minHeap {cost to reach B from C + cost to reach C = 4 + 3 = '7', B}, {cost to reach D from C + cost to reach C = 2 + 3 = 5, D}
Notice how B is pushed twice into the minHeap and still now popped. minHeap can contain a node multiples times because there could be
multiple paths to it and ofcourse minimum cost will be popped.

...continue

Time Complexity:
E.log(E); E in worst case -> V^2
if E is V^2 -> E* 2logV -> ElogV OR V^2 LogV OR V^2 LogE

Better to write E.logE or ElogV 

log(E) comes from minheap. Max size of min heap could be us adding all the edges assicated with a node as we already saw a node could be added
multiple time. When we push or pop that will be log(E).

How may time should we pop and push into the min heap? E times
For all the adges ; We are pushing all the edges into the queue and might 
pop all of them in worst case. Hence E*logE



*/

#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;

class Graph{
    int V;
    unordered_map<int,vector<pair<int,int>>> adj;
    unordered_map<int,int> shortest;
    
    public:
    Graph(int V)
    {
        this->V = V;
    }
    
    void addEdge(int v, int w, int cost)
    {
        adj[v].push_back({w,cost});
    }
    
    void dijkstra()
    {
        priority_queue<P, vector<P>, greater<P>> minHeap;
        
        minHeap.push({0,0});
 
        while(!minHeap.empty() and shortest.size()!=V)
        {
            
            auto curr_node_info = minHeap.top();
            minHeap.pop();
            
            int cost_till_curr = curr_node_info.first;
            int curr_node = curr_node_info.second;
            
            if(shortest.count(curr_node))
                continue;
                
            shortest[curr_node] = cost_till_curr;
            
            for(auto v: adj[curr_node])
            {
                int next_node = v.first;
                int cost_to_next = v.second;
                if(!shortest.count(next_node))
                    minHeap.push({(cost_to_next + cost_till_curr), next_node});
                    
            }
            
        }
        
        print_shortest();
    }
    
    void print_shortest()
    {
        for(auto i:shortest)
        {
            cout<<i.first<<":"<<i.second<<"\n";
        }
    }
};


int main()
{
    Graph g(5);
    g.addEdge(0,1,10);
    g.addEdge(0,2,3);
    g.addEdge(2,1,4);
    g.addEdge(1,3,2);
    g.addEdge(2,3,8);
    g.addEdge(2,4,2);
    g.dijkstra();
    
    return 0;
}











