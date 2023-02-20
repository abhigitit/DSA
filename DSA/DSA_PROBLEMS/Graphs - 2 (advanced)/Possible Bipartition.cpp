
/*

Possible Bipartition
Leetcode 886

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
    map<int,int> colors;
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
     
        for(int i=0;i<dislikes.size();++i)
        {
            int person1 = dislikes[i][0];
            int person2 = dislikes[i][1];
            adj[person1].push_back(person2);
            adj[person2].push_back(person1);
        }
        for(int i=1;i<n+1;++i)
        {
           colors[i] =-1;
        }
        
        for(int i=1;i<n+1;++i)
        {
        
            if(colors[i]==-1 and !isBipartite(i))
                return false;
        }
        return true;
    }
    
    bool isBipartite(int curr)
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
