/*
Detect cycle in directed graph
Main visited: If the node was ever visited from any starting point. (used to judge to even call a recursion on this; not required if a path was explored from this point)

Dfs visited: If node has been visited in the current dfs call stack or not. (to check if a node is visited more than once in one dfs call)

*/



#include <bits/stdc++.h>

using namespace std;

class Graph{

int V;
map<int,vector<int>> adj;
set<int> visited_main;
set<int> visited_dfs;



public:
Graph(int V)
{
    this->V=V;
}

void addEdges(int v,int w)
{
adj[v].push_back(w);
}

bool isCycle1(int source)
{
    
	 visited_main.insert(source);
	visited_dfs.insert(source);
	
	for(auto i:adj[source])
		{
		  if(!visited_main.count(i) and isCycle1(i))
			    return true;
		else if(visited_dfs.count(source))
		{
	    	return true;
		}
	visited_dfs.erase(source);
	return false;

}


bool isCycle()
{

    for(int i=0;i<V;++i)
        {
		if(!visited_main.count(i) and isCycle1(i))
			return true;
        }
    return false;
}

};


int main()
{
    Graph g(6);
    g.addEdges(0,1);
    g.addEdges(1,2);
    g.addEdges(1,3);
    g.addEdges(1,5);
    g.addEdges(2,3);
    g.addEdges(4,3);
    g.addEdges(5,4);
    g.addEdges(5,0);
    bool x = g.isCycle();
    cout<<x<<endl;

    return 0;
}
