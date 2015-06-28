class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int r = matrix.size();
        int c = matrix[0].size();
        int max = 0;
        vector<vector<int> > dp(r, vector<int>(c, 0));
        for(int i = 0; i < r; ++i) {
            dp[i][0] = matrix[i][0] - '0';
            max = dp[i][0] > max ? dp[i][0] : max;
        }
        for(int j = 0; j < c; ++j) {
            dp[0][j] = matrix[0][j] - '0';
            max = dp[0][j] > max ? dp[0][j] : max;
        }
        for(int i = 1; i < r; ++i) {
            for(int j = 1; j < c; ++j) {
                if(matrix[i][j] == '1') {
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))+1;
                    max = dp[i][j] > max ? dp[i][j] : max;
                }
            }
        }
        return max*max;
    }
};
