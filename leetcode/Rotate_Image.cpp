class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        vector<vector<int> > temp;
        int col = matrix[0].size();
        int row = matrix.size();
        for(int i=0;i<row;i++){
            vector<int> tmp;
            for(int j=0;j<col;j++){
                tmp.push_back(matrix[i][j]);
            }
            temp.push_back(tmp);
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                int tmpi = row-1 -j;
                int tmpj = i;
                matrix[i][j] = temp[tmpi][tmpj]; 
            }
        }
    }
};
