/*
Detonate the Maximum Bombs
*/

class Solution {
    map<int,vector<int>> adj;
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        
        for(int i=0;i<bombs.size();++i)
        {
            for(int j=i+1;j<bombs.size();++j)
            {

                vector<int> bomb1 = bombs[i];
                vector<int> bomb2 = bombs[j];
                int bomb1_range = bomb1[2];
                int bomb2_range = bomb2[2];
                int dist = calculateDist(bomb1,bomb2);

                if(dist<=bomb1_range)   adj[i].push_back(j);
                if(dist<=bomb2_range)   adj[j].push_back(i);

            }
            
        }
        int res = 1;
        for(auto it:adj)
        {
            set<int> visited;
            visited.insert(it.first);
            dfs(it.first,visited);
            int y = visited.size();
            res = max(res,y);
        }

        return res;
    }

    int calculateDist(vector<int>& bomb1,vector<int>& bomb2)
    {
        int x1 = bomb1[0];
        int y1 = bomb1[1];

        int x2 = bomb2[0];
        int y2 = bomb2[1];

        return sqrt(pow(x2-x1,2) + pow(y2-y1,2));
    }

    void dfs(int source, set<int>& visited)
    {
        
        for(auto nei:adj[source])
        {
            if(!visited.count(nei)) 
            {
                visited.insert(nei);
                dfs(nei,visited);
            }
        }
    }
};
