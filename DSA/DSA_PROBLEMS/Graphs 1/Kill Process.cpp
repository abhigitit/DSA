/*
Kill Process
BFS
*/

class Solution {
    map<int,vector<int>> adj;
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        
        for(int i=0;i<pid.size();++i)
        {
            adj[ppid[i]].push_back(pid[i]);
        }
        
        
        queue<int> bfs;
        vector<int> res;
        bfs.push(kill);
        
        while(bfs.size())
        {
            int to_kill = bfs.front();
            bfs.pop();
            res.push_back(to_kill);
            
            if(adj.count(to_kill))
            {
                for(auto it:adj[to_kill])
                    bfs.push(it);
            }
            
        }
        return res;
    }
};
