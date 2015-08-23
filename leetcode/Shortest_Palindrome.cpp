class Solution {
public:
    string shortestPalindrome(string s) {
        string rs = s;
        reverse(rs.begin(), rs.end());
        string p = s + "#" + rs;
        int lenp = p.size();
        int longestPrefixSuffix[lenp];
        longestPrefixSuffix[0] = -1;
        for (int i = 1; i < lenp; ++i) {
            int j = longestPrefixSuffix[i-1];
            while (j > -1 && p[i] != p[j+1]) j = longestPrefixSuffix[j];
            if (p[i] == p[j+1]) ++j;
            longestPrefixSuffix[i] = j;
        }
        return rs.substr(0, s.size() - longestPrefixSuffix[lenp-1]-1) + s;
    }
};
