class Solution {
    vector<vector<int> > min_val;
public:
    int minPathSum(vector<vector<int> > &grid) {
        int sum = INT_MAX;
        int m = grid.size();
        if(m<1) return sum;
        int n = grid[0].size();
        min_val = vector<vector<int> >(m, vector<int>(n, -1));
        min_val[0][0] = grid[0][0];
        return minSum(grid, m-1, n-1);
    }
    
    int minSum(const vector<vector<int> > &grid, int m, int n){
        if(min_val[m][n] != -1) return min_val[m][n];
        else{
            if(m==0){
                min_val[m][n] = minSum(grid, m, n-1) + grid[m][n];
            }else if(n==0){
                min_val[m][n] = minSum(grid, m-1, n) + grid[m][n];
            }else{
                int temp1 = minSum(grid, m-1, n) + grid[m][n];
                int temp2 = minSum(grid, m, n-1) + grid[m][n];
                min_val[m][n] = min(temp1, temp2);
            }
            return min_val[m][n];
        }
    }
};
