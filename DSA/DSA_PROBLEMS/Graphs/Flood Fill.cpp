/*
Flood Fill

*/

class Solution {
public:
    int x;
    vector<vector<int>> res;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        this->x = image[sr][sc];
        res = image;
        for(int i=0;i<image.size();++i)
        {
            for(int j=0;j<image[0].size();++j)
            {
                if(i==sr and j==sc)
                {
                    DFS(i,j,image,color);
                }
            }
        }
        return res;
    }
    
    void DFS(int i, int j,vector<vector<int>>& image,int color)
    {
        if(i<0 or j<0 or i>=image.size() or j>=image[0].size() or image[i][j]!=x)
            return;
        
        if(image[i][j]==x)
            res[i][j]=color;
        
        image[i][j] = -1;
        
        DFS(i+1,j,image,color);
        DFS(i-1,j,image,color);
        DFS(i,j+1,image,color);
        DFS(i,j-1,image,color);
        
    }
};
