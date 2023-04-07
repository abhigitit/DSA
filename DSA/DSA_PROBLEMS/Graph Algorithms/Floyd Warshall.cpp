/*
Floyd Warshall Algorithm : All pairs shortest path.

Shortest path between all pairs of vertices is calculated.

Adj matrix'

what is my shortest path from i to j via k;
k takes all values from 0 to n
{
min distance of all nodes to all nodes via k //two for loops
}

https://www.youtube.com/watch?v=nV_wOZnhbog

Algorithm:
*/

        dist.resize(n,vector<int>(n,1e9));
        
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                  if(i==j)
                    dist[i][j] = 0;//self distance 0
                }
            }
        
//update with given costs
        for(int i=0;i<edges.size();++i)
        {
            int v = edges[i][0];
            int w = edges[i][1];
            int cost = edges[i][2];
            dist[v][w] = cost;
            dist[w][v] = cost;
        }

//compute all costs from all nodes to all nodes
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

