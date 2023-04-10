/*

Flower Planting With No Adjacent
M coloring
https://www.youtube.com/watch?v=wuVwUK25Rfc&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=18

*/
class Solution {
    map<int,vector<int>> adj;
    map<int,int> colors;
    vector<int> res;

    bool safeToPlant(int garden, int i)
    {
        for(auto nei:adj[garden])
        {
            if(colors[nei]==i)
                return false;
        }
        return true;
    }
    void buildRes()
    {
        for(auto it:colors)
        {
            res.push_back(it.second);
        }
    }
    bool backtrack(int garden, int n)
    {
        if(garden>n)
        {
            buildRes();
            return true;
        }

        for(int i=1;i<=4;++i)
        {
            if(safeToPlant(garden,i))
            {
                 colors[garden]=i;
                 if(backtrack(garden+1,n))
                    return true;
                 colors[garden]=0;
            }
                 
        }
        return false;
    }

public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        
        for(int i=0;i<paths.size();++i)
        {
            int u = paths[i][0];
            int v = paths[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }


    backtrack(1,n);
    return res;

    }
};
