/*
Number of Provinces
*/
class Solution {
public:
    vector<vector<int>> adj;
    set<int> visited;
    int province = 0;
    int findCircleNum(vector<vector<int>>& isConnected) {
       int N = isConnected.size();
        
        for(int i=0;i<N;++i)
        {
            if(!visited.count(i))
            {
                dfs(i,isConnected);
                province++;
            }
        }
        return province;
    }
    
    void dfs(int source,vector<vector<int>>& isConnected)
    {
       visited.insert(source);
        
        for(int i=0;i<isConnected[source].size();++i)
        {
            if(isConnected[source][i]==1 and !visited.count(i))
                dfs(i,isConnected);
        }
    }
};
