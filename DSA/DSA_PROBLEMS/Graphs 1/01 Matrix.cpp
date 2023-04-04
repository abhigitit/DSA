/*
01 Matrix

A 1 should have nearest 0. Start from 0 and reach 1
*/

class Solution {
public:
vector<vector<int>> dist;
vector<vector<int>> visited;
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        visited.resize(rows,vector<int>(cols,0));
        dist.resize(rows,vector<int>(cols,0));
        queue<vector<int>> nearest;
        vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
        for(int i=0;i<rows;++i)
        {
            for(int j=0;j<cols;++j)
            {
                if(mat[i][j]==0)
                {
                    nearest.push({i,j,0});
                    visited[i][j]=1;
                }
                    
            }
        }
    cout<<nearest.size()<<endl;
        while(!nearest.empty())
        {
            
                vector<int> curr = nearest.front();
                nearest.pop();
                int x = curr[0];
                int y = curr[1];
                int distance = curr[2];

                dist[x][y] = distance;
           
                for(int j=0;j<directions.size();++j)
                {
                    int new_x = x + directions[j][0];
                    int new_y = y + directions[j][1];

                    if(min(new_x,new_y)<0 or new_x==rows or new_y==cols or visited[new_x][new_y])
                        continue;

                    visited[new_x][new_y]=1;
                    nearest.push({new_x,new_y,distance+1});
                }

        }
    return dist;

    }
};
