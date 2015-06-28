class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char check_s[256];
        char check_t[256];
        fill(check_s, check_s+256, 0);
        fill(check_t, check_t+256, 0);
        if(s.size() != t.size()) return false;
        for(int i = 0; i < s.size(); ++i) {
            //btl(s[i]); btl(t[i]);
            int index_s = s[i];
            int index_t = t[i];
            if(check_s[index_s] == 0 && check_t[index_t] == 0) {
                check_s[index_s] = t[i];
                check_t[index_t] = s[i];
            }else if(check_s[index_s] != t[i] || check_t[index_t] != s[i])
                return false;
        }
        return true;
    }

};
