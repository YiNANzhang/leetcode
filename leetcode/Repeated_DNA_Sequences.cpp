class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if (s.size() <= 10) return res;
        unordered_map<int, int> map;
        int i = 0, code = 0, n = s.size();
        while (i < 9) code = code << 3 | s[i++] & 7;
        while(i < n) { 
            if (map[code = 0x3fffffff & (code << 3 | (s[i++] & 7))]++ == 1) 
                res.push_back(s.substr(i-10, 10));
        }
        return res;
    }
};
