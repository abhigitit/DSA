/*
Is Graph Bipartite?

Intuition : Bipartite graph
We can divide the nodes into two disjoint sets such that all the edges contain one node from one set an another from second set.
If there is an odd length cycle, that means nodes from the same set are connected.

Use graph coloring to find odd length cycle.

https://www.youtube.com/watch?v=0ACfAqs8mm0&ab_channel=TECHDOSE

TC: O(E+V) E comes from making adjacency list and V from coloring.

*/
class Solution {
public:
    map<int,vector<int>> adj;
    bool isBipartite(vector<vector<int>>& graph) {
        
      for(int i=0;i<graph.size();++i)
      {
          for(int j=0;j<graph[i].size();++j)
          {
              adj[i].push_back(graph[i][j]);
          }
      }
        vector<int> colors(graph.size(),-1);
     for(int i=0;i<graph.size();++i)
        {
        
            if(colors[i]==-1 and !helper(i,colors))
                return false;
        }
        return true;
    }
    
    bool helper(int curr,vector<int>& colors)
    {
        queue<int> BFS;
        BFS.push(curr);
        colors[curr] = 1;
        while(!BFS.empty())
        {
            curr = BFS.front();
            BFS.pop();
            for(auto i:adj[curr])
            {
                if(colors[i]==colors[curr])
                    return false;
                if(colors[i]==-1)
                {
                   colors[i] = 1 - colors[curr];
                    BFS.push(i);
                }
               
            }
        }
        return true;
    }
};
