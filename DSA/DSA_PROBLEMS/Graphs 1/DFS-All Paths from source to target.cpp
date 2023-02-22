/*
Count of All Paths from source to target
Print paths from source to target

DFS with backtracking

TC : Suppose N is the average number of choices from each vertex(number of decisions) and the max lenght of path would be V (height of decision tree).
O(N power V)
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
    
    int count_paths(int source, int target)
    {
        if(source==target)
            return 1;
            
        visited.insert(source);
        int count = 0;
        
        for(auto v:adj[source])
        {
            if(!visited.count(v))
                count += count_paths(v,target);
        }
        
        visited.erase(source);
        
        return count;
    }
    
    vector<string> print_paths(int source, int target)
    {
        string path = "";
        paths(source,target,path);
        return res;
    }
    string paths(int source, int target, string path)
    {
        path+=to_string(source);
        if(source == target)
        {
            res.push_back(path);
        }
        
        visited.insert(source);
        
        
         for(auto v:adj[source])
        {
            if(!visited.count(v))
                paths(v,target, path);
        }
        
        visited.erase(source);
        
        return path;
        
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
    
    int count = g.count_paths(0,6);
    vector<string> res = g.print_paths(0,6);
    
    cout<<count<<"\n";
    
    for(auto c:res)
    {
        cout<<c<<"\n";
    }
    
    return 0;
}
