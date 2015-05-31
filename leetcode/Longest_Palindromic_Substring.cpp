class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        //vector<vector<bool> > flag(n, vector<bool>(n, false));
        //for(int i = 0; i < n; ++i) {
        //    flag[i][i] = true;
        //}
        //string ret;
        bool flag[n][n];
        fill_n(&flag[0][0], n*n, false);
        int start = 0;
        int length = 1;
        for(int i = 0; i < n; ++i) {
            flag[i][i] = true;
            for(int j = 0; j < i; ++j) {
                if(s[i] == s[j] && (i - j < 2  || flag[j+1][i-1]))
                    flag[j][i] = true;
                if(flag[j][i] && (i - j + 1) > length) {
                    length = i - j + 1;
                    start = j;
                }
            }
        }
        return s.substr(start, length);
        //return ret;
    }
};
