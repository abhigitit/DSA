/*
Range Sum Query 2D - Immutable

Calculate prefix sum for each with the running sum and add prefix sum of above cell.
So that a whole portion (as the current cell being the right bottom) sum is known.

*/

class NumMatrix {
public:
vector<vector<int>> prefix_matrix;
int rows;
int cols;
    NumMatrix(vector<vector<int>>& matrix) {
        rows = matrix.size();
        cols = matrix[0].size();
        prefix_matrix.resize(rows+1,vector<int>(cols+1,0));
        fillPrefixMatrix(matrix);
    }
    void fillPrefixMatrix(vector<vector<int>>& matrix)
    {
        for(int i=0;i<rows;++i)
        {
            int prefixsum=0;
            for(int j=0;j<cols;++j)
            {
                prefixsum+=matrix[i][j];
                int above = prefix_matrix[i][j+1];
                prefix_matrix[i+1][j+1] = prefixsum + above;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        row1 = row1+1;
        row2 = row2+1;
        col1 = col1+1;
        col2 = col2+1;

        int bottomright = prefix_matrix[row2][col2];
        int above = prefix_matrix[row1-1][col2];
        int left = prefix_matrix[row2][col1-1];
        int topleft = prefix_matrix[row1-1][col1-1];

        return bottomright - above - left + topleft;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
