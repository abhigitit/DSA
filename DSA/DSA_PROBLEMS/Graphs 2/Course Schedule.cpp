/*
COurse Schedule 207

Intuition : Has a cycle

Use a map and mark true false and do not use set to add remove vertices because, if a vertex is removed from set in backtracking, and the next time
the vertex is visited again, the code is executed again.

With map, the node can be mapped to false but its still there inside map..so when we reach it again, we caan return false for cycle because the
paths from that node have already been explored.

O(V+E)

*/
class Solution {
public:
    map<int,vector<int>> adj;
    map<int,bool> visited;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        for(int i=0;i<prerequisites.size();++i)
        {
            int v = prerequisites[i][0];
            int w = prerequisites[i][1];
            adj[w].push_back(v);
        }
        
        bool flag = true;
        for(auto s:adj)
        {
            if(hasCycle(s.first))
                flag=false;
        }
        
        return flag;
    }
    
    bool hasCycle(int s)
    {
        if(visited.find(s)!=visited.end())
            return visited[s];
        
        visited[s] = true;
        
        
        for(auto i:adj[s])
        {
            if(hasCycle(i))
                return true;
        }
         visited[s] = false;
        return false;
        
    }
};
