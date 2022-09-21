/*
Leetcode 210

Intuition : Topological sort with has a cycle

*/

class Solution {
public:
    stack<int> topo;
    map<int,vector<int>> adj;
    map<int,bool> visited;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         vector<int> res;
        if(prerequisites.size()==0 and numCourses>0)
        {
            for(int i=0;i<numCourses;++i)
            {
                res.push_back(i);
            }
            return res;
        }
            
   for(int i=0;i<prerequisites.size();++i)
        {
            int v = prerequisites[i][0];
            int w = prerequisites[i][1];
            adj[w].push_back(v);
        }
  
        for(auto s:adj)
        {
            if(hasCycle(s.first))
                return {};
        }
        
        while(!topo.empty())
        {
            res.push_back(topo.top());
            topo.pop();
        }
        return res;
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
        topo.push(s);
         visited[s] = false;
        return false;
        
    }
};
