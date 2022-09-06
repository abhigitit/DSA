/*

Given an N x M matrix, containing distinct elements, return all special values.
Note: A special value in the matrix is an element that is the minimum element in the its row and the maximum element in its column.

matrix = [
  [1, 2, 5],
  [4, 8, 3],
  [9, 7, 6]
], return [6].

*/

#include <bits/stdc++.h>

using namespace std;


vector<int> special_values(vector<vector<int>> grid)
{
    map<int,vector<pair<int,int>>> rows;
    map<int,vector<pair<int,int>>> cols;
    set<pair<int,int>> temp;
    vector<int> res;
    int r=grid.size();
    int c=grid[0].size();
    for(int i=0;i<r;++i)
    {
        for(int j=0;j<c;++j)
        {
           rows[i].push_back({grid[i][j],j});
           cols[j].push_back({grid[i][j],j});
        }
    }
    
   for(int i=0;i<r;++i)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> min_heap;
        for(auto j:rows[i])
        min_heap.push(j);
        
        temp.insert(min_heap.top());
        
    }
    
    for(int j=0;j<c;++j)
    {
        priority_queue<pair<int,int>> max_heap;
        for(auto i:cols[j])
        max_heap.push(i);
        
        if(temp.count(max_heap.top()))
        res.push_back(max_heap.top().first);
        
    }
    
  
        return res;
    
}

int main()
{
    
    vector<vector<int>> grid = {{1,2,5},{4,8,3},{9,7,6},{100,99,90}};
    vector<int> res = special_values(grid);

    for(auto i:res)
    {
        cout<<i<<endl;
    }
    return 0;
}
