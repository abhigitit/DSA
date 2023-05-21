/*
Leftmost Column with at Least a One
*/
class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> size = binaryMatrix.dimensions();
        int rows = size[0];
        int cols = size[1];
        int x = rows-1;
        int y = cols-1;
        int res = INT_MAX;
        while(y>=0 and x>=0)
        {
 
            if(binaryMatrix.get(x,y)==1) 
            {
                 res = min(res,y);
                 y--;
            }
            else
                x--;
               
        }
        return res!=INT_MAX ? res : -1;
    }
};
