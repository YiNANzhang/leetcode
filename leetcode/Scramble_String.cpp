class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        int n = s1.size();
        bool dp[n][n][n];
        fill_n(&dp[0][0][0], n*n*n, false);
        for (int i = 0; i < s1.size(); ++i) {
            for (int j = 0; j < s2.size(); ++j) {
                    dp[i][j][0] = s1[i] == s2[j];
            }
        }
		for (int l = 1; l < n; ++l) {

        //bool flag = false;
        	for (int i = 0; i+l<n; ++i) {
            	for (int j = 0; j+l < n; ++j) {
                    for (int k = 0; k < l; ++k) {
												if ( (dp[i][j][k] && dp[i+k+1][j+k+1][l-k-1]) || (dp[i][j+l-k][k] && dp[i+k+1][j][l-k-1])) {
                            dp[i][j][l] = true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[0][0][n-1];
    }
};

