class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        bool col_flag[cols];
        fill(col_flag, col_flag+cols, false);
        for(int i=0; i<rows; ++i) {;
            bool row_flag = false;
            for(int j=0; j<cols; ++j) {
                if(matrix[i][j] == 0) {
                    col_flag[j] = true;
                    row_flag = true;
                    //for(int k=0; )
                }
            }
            if(row_flag == true) {
                for(int k=0; k<cols; ++k) {
                    matrix[i][k] = 0;
                }
            }
        }
        for(int k=0; k<cols; ++k) {
            if(col_flag[k] == true) {
                for(int i=0; i<rows; i++) {
                    matrix[i][k] = 0;
                }
            }
        }
    }
};
