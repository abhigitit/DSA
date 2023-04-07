/*

Find the City With the Smallest Number of Neighbors at a Threshold Distance

Floyd marshall

*/

class Solution {
    vector<vector<int>> dist;
    vector<int> res;
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        dist.resize(n,vector<int>(n,1e9));
        res.resize(n);
        for(int i=0;i<edges.size();++i)
        {
            int v = edges[i][0];
            int w = edges[i][1];
            int cost = edges[i][2];
            dist[v][w] = cost;
            dist[w][v] = cost;
        }

        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }

        for(int i=0;i<n;++i)
        {
            int canReach = 0;
            for(int j=0;j<n;++j)
            {
                if(i!=j and dist[i][j]<=distanceThreshold)
                    canReach++;
            }
            res[i] = canReach;
        }

        int min_idx = 0;
        int lowest_reach = res[0];
        for(int i=1;i<n;++i)
        {
            if(res[i]<=lowest_reach)
            {
                 min_idx = i;
                 lowest_reach = res[i];
            }
           
        }

    return min_idx;
    }
};
