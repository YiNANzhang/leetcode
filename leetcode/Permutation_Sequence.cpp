class Solution {
    //vector<int> factor;
public:
    string getPermutation(int n, int k) {
        string s(n, '0');
        for(int i = 0; i < n; ++i) {
            s[i] += i+1;
        }
        if(k == 1) return s;
        //factor.push_back(1);
        int base = 1;
        for(int i = 2; i < n; ++i) {
            base *= i;
        }
        string ret;
        //int j = k;
        //--k;
        for(int j = n-1; j > 0; base /= j,--j) {
            if(k == 0) {
                reverse(s.begin(), s.end());
                break;
            }
            if(k == 1) {
                break;
            }
            ret += s[(k-1) / base];
            s.erase((k-1) / base, 1);
            k = k % base;
        } 
        ret += s;
        return ret;
    }
};
