/*
BFS - Shortest Length from source to target.cpp

*/

#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    unordered_map<int,vector<int>> adj;
    set<int> visited;
    vector<string> res;
    public:
    Graph(int V)
    {
        this->V = V;
    }
    
    void addEdges(int v, int w)
    {
        adj[v].push_back(w);
    }
    
    int shortest_length(int source, int target)
    {
        queue<int> bfs;
        bfs.push(source);
        visited.insert(source);
        int length = 0;
        
        while(!bfs.empty())
        {
            for(int i=0;i<bfs.size();++i)
            {
                source = bfs.front();
                bfs.pop();
                if(source==target)
                    return length;
            
                for(auto v:adj[source])
                    {
                        if(!visited.count(v))
                            {
                             visited.insert(v);
                             bfs.push(v);
                             }
                    } 
            }
           
        length++;
        }
        
    return length;
    }
  
};

int main()
{
    Graph g(7);
    
    g.addEdges(0,1);
    g.addEdges(1,5);
    g.addEdges(5,6);
    g.addEdges(0,2);
    g.addEdges(0,6);
    g.addEdges(2,1);
    g.addEdges(1,3);
    g.addEdges(3,4);
    g.addEdges(4,5);
    
    int shortest_length = g.shortest_length(0,6);
    
    cout<<shortest_length<<"\n";
    
 
    
    return 0;
}


