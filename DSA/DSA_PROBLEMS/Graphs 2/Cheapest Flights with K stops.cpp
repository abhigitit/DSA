/*
Leetcode: 787

Intution : Apply bellman ford. The shortest paths will be updated. However, we have constraint to at most stops k i.e minimum nodes between source
and destination.

Loop for only k times. As cost of source is 0 initially in distance array, update all the edges connected to source i.e go only 1 level deeper. Then in next
iteration go another level deeper and update 2nd level nodes. repeat k times. 
Take help of temp distances array for this approach.

https://www.youtube.com/watch?v=5eIK3zUdYmE&ab_channel=NeetCode

TC:O(kE)

*/

class Solution {
public:
    int V;
    vector<vector<int>> edges;
    vector<int> cost;
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
      
        cost.resize(n,INT_MAX);
        cost[src] = 0;
      
 
        for(int i=0;i<k+1;++i)
        {
           
            vector<int> temp = cost;
            for(int j=0;j<flights.size();j++)
            {
                int u = flights[j][0];
                int v = flights[j][1];
                int wt = flights[j][2];
                
                if(cost[u]!=INT_MAX and cost[u]+wt < temp[v])
                {
  
                    temp[v] = cost[u]+wt;
    
                }
            }
            cost = temp;
           
        }
        
        return cost[dst]!=INT_MAX?cost[dst]:-1;
        
        
    }
};
