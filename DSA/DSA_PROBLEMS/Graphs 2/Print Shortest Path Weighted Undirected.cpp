/*
Print Shortest Path Weighted Undirected
Dijkstras with remembering parent

*/


#include<bits/stdc++.h>
using namespace std;
typedef vector<int> P;

class Graph{
    int V;
    unordered_map<int,vector<pair<int,int>>> adj;
    unordered_map<int,int> shortest;
    vector<int> parent;
    public:
    Graph(int V)
    {
        this->V = V;
        for(int i=0;i<V;++i)
       {
           parent.push_back(i);
       }
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
            
            int cost_till_curr = curr_node_info[0];
            int curr_node = curr_node_info[1];
            int parent_node = curr_node_info[2];
            if(shortest.count(curr_node))
                continue;
                
            shortest[curr_node] = cost_till_curr;
            parent[curr_node] = parent_node;
            for(auto v: adj[curr_node])
            {
                int next_node = v.first;
                int cost_to_next = v.second;
                if(!shortest.count(next_node))
                {
                    minHeap.push({(cost_to_next + cost_till_curr), next_node,curr_node});
                    
                }
                    
                    
            }
            
        }
        
        print_shortest();
        print_path();
    }
    
    void print_shortest()
    {
        for(auto i:shortest)
        {
            cout<<i.first<<":"<<i.second<<"\n";
        }
    }
    
    void print_path()
    {
        int n = V-1;
        
        while(n!=parent[n])
        {
            cout<<n<<",";
            n=parent[n];
        }
        cout<<n<<endl;
    }
};


int main()
{
    Graph g(6);
    g.addEdge(0,1,4);
    g.addEdge(0,2,4);
    g.addEdge(2,1,2);
    g.addEdge(2,3,3);
    g.addEdge(2,4,1);
    g.addEdge(2,5,6);
    g.addEdge(3,5,2);
    g.addEdge(4,5,3);
    g.dijkstra();
    
    return 0;
}











