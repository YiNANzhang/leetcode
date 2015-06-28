class Solution {
public:
    bool isMatch(string s, string p) {
		if (s.size() == 0 && p.size() == 0) return true;
		if (p.size() == 0) return false;
		
		return isMatch(s, p, 0, 0);	    
    }

	bool isMatch(string &s, string &p, int i, int j) {
		if (j == p.size()) return i == s.size();
		
		if (j == p.size()-1 || p[j+1] != '*') {
			if (i == s.size()) return false;
			return (s[i] == p[j] || p[j] == '.')  && isMatch(s, p, ++i, ++j);
		}
		
		while (i < s.size() && (p[j] == '.' || s[i] == p[j])) {
			if (isMatch(s, p, i, j+2)) return true;
			i++;
		}
		
		return isMatch(s, p, i, j+2);
	}
};
