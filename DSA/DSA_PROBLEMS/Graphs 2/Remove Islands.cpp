
/*
Remove Island Algo Expert
*/


#include <bits/stdc++.h>

using namespace std;
void DFS(int i,int j, vector<vector<int>> &matrix,vector<pair<int,int>>& adj);
void checkBoundaries(vector<pair<int,int>>& adj,vector<vector<int>> &matrix);
void eraseMatrix(vector<pair<int,int>>& adj,vector<vector<int>> &matrix);
vector<vector<int>> removeIslands(vector<vector<int>> &matrix) {
 

  for(int i=0;i<matrix.size();++i)
    {
      for(int j=0;j<matrix[i].size();++j)
        {
          vector<pair<int,int>> adj;
          if(matrix[i][j]==1)
          {
            DFS(i,j,matrix,adj);
            checkBoundaries(adj,matrix);
          }
          
        }
    }
   
     for(int i=0;i<matrix.size();++i)
    {
      for(int j=0;j<matrix[i].size();++j)
        {
          if(matrix[i][j]==-1)
          {
           matrix[i][j]=1;
          }
          
        }
    }
return matrix;

}

void DFS(int i,int j, vector<vector<int>> &matrix, vector<pair<int,int>>& adj)
{
  
  
  if(i<0 || j<0 || i>=matrix.size() || j>=matrix[i].size() || matrix[i][j]!=1) return;
  if(matrix[i][j]==1) adj.push_back(make_pair(i,j));
  matrix[i][j] = -1;
  DFS(i+1,j,matrix,adj);
  DFS(i-1,j,matrix,adj);
  DFS(i,j+1,matrix,adj);
  DFS(i,j-1,matrix,adj);
}

void checkBoundaries(vector<pair<int,int>>& adj,vector<vector<int>> &matrix)
{
    int flag =0;
    for(auto a:adj)
      {
      int i = a.first;
      int j = a.second;
      if(j==matrix[0].size()-1 or i==0 or i==matrix.size()-1 or j==0)
         flag = 1;
    }
        if(flag==0) eraseMatrix(adj,matrix);
        return;
        

}


void eraseMatrix(vector<pair<int,int>>& adj,vector<vector<int>> &matrix)
{
  for(auto a:adj)
    {
      int i = a.first;
      int j = a.second;
      matrix[i][j]=0;
    }
}
