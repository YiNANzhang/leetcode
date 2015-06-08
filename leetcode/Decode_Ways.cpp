class Solution {
public:
    int numDecodings(string s) {
        if(s.size()==0 || s[0] == '0')  return 0;
        int cur=1, prev=1;
        for(int i=1;i<s.size();i++){
            if(s[i] == '0')  cur=0;
            if(!(s[i-1] == '1' || (s[i-1] == '2' && s[i]<='6') ))
                prev = 0;
            int temp = cur;
            cur += prev;
            if(cur==0) return 0;
            prev = temp;
        }
        return cur;
    }
};
