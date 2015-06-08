class Solution {
public:
  bool isMatch(string s, string p) {
    int lens = s.size(), lenp = p.size();
    bool star = false;
    int sbegin, pbegin, i, j;
    for(sbegin = 0,pbegin = 0, i = 0, j = 0; j < lens;) {
        if(p[i] == '?' || s[j] == p[i]) {
            i++;
            j++;
        }else if(p[i] == '*') {
            star = true;
            pbegin = i++; 
            sbegin = j;
            while(pbegin < lenp && p[pbegin] == '*') pbegin++;
            if(pbegin == lenp) return true;
            i = pbegin;
        }else{
            if(!star) return false;
            j = sbegin++;
            i = pbegin;
        }
    }
    while(i < lenp && p[i] == '*') i++;
    return i == lenp;
  }
};
