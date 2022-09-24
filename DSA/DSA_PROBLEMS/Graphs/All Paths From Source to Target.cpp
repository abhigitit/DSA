/*
All Paths From Source to Target
*/

class Solution {
public:
     vector<vector<int>> res;
    vector<bool> visited;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    visited.resize(graph.size(),false);
        vector<int> temp;
        DFS(0,graph.size()-1,temp,graph);
        return res;
    }
    
    void DFS(int source,int dest,vector<int> temp,vector<vector<int>>& graph)
    {
        visited[source] = 1;
        temp.push_back(source);
        if(source==dest)
        {
            res.push_back(temp);
        }
        else{
            for(int i=0;i<graph[source].size();++i)
        {
           if(!visited[graph[source][i]])
               DFS(graph[source][i],dest,temp,graph);
        } 
        }
       
        temp.pop_back();
        visited[source] = 0;
    }
};
