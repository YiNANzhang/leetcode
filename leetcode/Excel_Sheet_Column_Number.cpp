class Solution {
public:
    int titleToNumber(string s) {
        string::size_type n = s.size();
        string::size_type i;
        int sum = 0;
        for(i=0;i<n;i++){
            sum = sum*26 + s[i]+1-'A';
        }
        return sum;
    }
};
