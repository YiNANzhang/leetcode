class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int state = 0; /* 0:left, 1:down, 2:right, 3:up*/
        vector<int> result;
        if(matrix.empty())return result;
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0;
        int row = 0, col = 0;
        int rb = n-1, lb = 0, db = m-1, ub = 1;
        while(i < m*n) {
            result.push_back(matrix[row][col]);
            if(state == 0) {
                if(col == rb) {
                    state = 1;
                    row++;
                    rb--;
                }else{
                    col++;
                }
            }else if(state == 1) {
                if(row == db) {
                    state = 2;
                    col--;
                    db--;
                }else{
                    row++;
                }
            }else if(state == 2) {
                if(col == lb) {
                    state = 3;
                    row--;
                    lb++;
                }else{
                    col--;
                }
            }else if(state == 3) {
                if(row == ub) {
                    state = 0;
                    col++;
                    ub++;
                }else{
                    row--;
                }
            }
            i++;
        }
        return result;
    }
};
