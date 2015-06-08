class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int> > f(t.size()+1, vector<int>(s.size()+1));
        for(int i = 0; i <= s.size(); ++i) {
            f[0][i] = 1;
        }
        
        for(int i = 1; i <= t.size(); ++i) {
            for(int j = 1; j <= s.size(); ++j) {
                if(s[j-1] == t[i-1]) f[i][j] = f[i-1][j-1] + f[i][j-1];
                else f[i][j] = f[i][j-1];
            }
        }
        return f[t.size()][s.size()];
    }
};
