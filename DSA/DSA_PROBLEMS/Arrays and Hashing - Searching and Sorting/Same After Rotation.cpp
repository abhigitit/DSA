/*
Given two n*n matrices, return true if the second matrix can be obtained by rotating first matrix by 90/180/270/360 degrees.
*/

#include <bits/stdc++.h>

using namespace std;



bool same_after_rotation(vector<vector<int>> &grid1,vector<vector<int>> &grid2)
{
   for(int z=0;z<4;++z)
   {
       vector<vector<int>> tmp = grid1;
       for(int i=0;i<grid1.size();++i)
       
       {
           int c = grid1.size() - 1 - i;
           for(int j=0;j<grid1[i].size();++j)
           {
               int r = j;
               tmp[r][c] = grid1[i][j];
           }
       }
       grid1 = tmp;
       if(grid1==grid2) return true;
   }
   return false;

}
int main()
{
    vector<vector<int>> grid1 = {{1,2,3},{4,5,6},{7,8,9}}; 
    vector<vector<int>> grid2 = {{7,4,1},{8,5,2},{9,6,3}}; 
    cout<<same_after_rotation(grid1,grid2);
    return 0;
}
