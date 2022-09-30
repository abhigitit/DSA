/*
Coding Ninjas
Rat In A Maze

*/

#include <bits/stdc++.h> 
 vector<string> res;
vector<vector<bool>> visited;
void backtrack(int i,int j,vector < vector < int >> & arr, string move,int n)
{
    if(i==n-1 and j==n-1)
    {
        res.push_back(move);
        return;
    }
        
    
    if(i<0 or j<0 or i>=arr.size() or j>=arr[i].size() or visited[i][j] or arr[i][j]!=1)
        return;
    visited[i][j]=true;
    backtrack(i+1,j,arr,move+'D',n);
    backtrack(i,j-1,arr,move+'L',n);
    backtrack(i,j+1,arr,move+'R',n);
    backtrack(i-1,j,arr,move+'U',n);
    
    visited[i][j]=false;
}
vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    if(arr[0][0]!=1) return {};
    
    visited.resize(arr.size(),vector<bool>(arr[0].size(),false));
    if(arr[0][0]==1) backtrack(0,0,arr,"",n);
    return res;
}
