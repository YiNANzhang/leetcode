class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int rown = dungeon.size();
        int coln = dungeon[0].size();
        vector<vector<int>> dp(rown+1, vector<int>(coln+1, INT_MAX));
        dp[rown-1][coln] = 1;
        dp[rown][coln-1] = 1;
        for (int i = rown-1; i >= 0; --i) {
            for (int j = coln-1; j >= 0; --j) {
                int need = min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j];
                dp[i][j] = need <= 0 ? 1 : need;
            }
        }
        return dp[0][0];
    }
};
