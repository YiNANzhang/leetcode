class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        //int k = s3.size();
        int m = s2.size();
        int n = s1.size();
        if( n + m != s3.size() ) return false;
        if( n == 0 || m == 0) return s3 == s1 + s2;
        //bool dp[n+1][m+1];
        //fill_n(&dp[n+1][m+1], (m+1)*(n+1), true);
        vector<vector<bool> > dp(n+1, vector<bool>(m+1, true));
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = dp[i-1][0] && s3[i-1] == s1[i-1]; 
        }
        for (int j = 1; j <= m; ++j) {
            dp[0][j] = dp[0][j-1] && s3[j-1] == s2[j-1];
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = dp[i-1][j] && s3[i+j-1] == s1[i-1] || (dp[i][j-1] && s3[i+j-1] == s2[j-1]);
            }
        }
        return dp[n][m];
    }
};

