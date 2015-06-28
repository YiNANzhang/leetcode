class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> num(n+1);
        bool flag[n][n];
        fill_n(&flag[0][0], n*n, false);
        num[0] = -1;
        for(int i = 0; i <= n; ++i) {
            num[i] = i-1;
//            flag[i][i] = true;
        }
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j <= i; ++j) {
                if(s[i] == s[j] && (i-j < 2 || flag[j+1][i-1]) ) {
                    flag[j][i] = true;
                    num[i+1] = min(num[i+1], num[j]+1);
                }
            } 
        }
        return num[n];
    }
};
