/*
COurse Schedule 207

Intuition : Has a cycle

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
