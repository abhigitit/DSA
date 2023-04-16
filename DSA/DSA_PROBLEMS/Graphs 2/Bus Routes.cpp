/*
Bus Routes

https://www.youtube.com/watch?v=FdJrq60KR1I

*/
class Solution {
    map<int,vector<int>> adj;
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target) return 0;
        set<int> visited_bus;
        set<int> visited_stop;
        for(int i=0;i<routes.size();++i)
        {
            int n = routes[i].size();
            for(int j=0;j<n;++j)
            {
                adj[routes[i][j]].push_back(i);
            }
        }

        queue<vector<int>> bfs;
        bfs.push({source,0});
        while(!bfs.empty())
        {
            auto curr = bfs.front();
            bfs.pop();
            int stop = curr[0];
            int dist = curr[1];
            if(stop==target)
                return dist;

            for(auto bus:adj[stop])
            {
                if(!visited_bus.count(bus))
                {
                    visited_bus.insert(bus);
                    for(auto nxt_stop:routes[bus])
                    {
                        if(!visited_stop.count(nxt_stop))
                        {
                            visited_stop.insert(nxt_stop);
                            bfs.push({nxt_stop,dist+1});
                        }
                    }
                }
            }
            
            

        }
        return -1;


    }
};
