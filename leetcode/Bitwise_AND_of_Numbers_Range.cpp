class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m == n) return m;
        int result = 0;
        int bits;
        for(bits = sizeof(int)*8-2; bits>=0; --bits){
            if( n < 1<<bits) continue;
            if( n >= 1<<bits && m< 1<<bits) {
                return result;
            } else {
              result = result | (1<< bits);
              m &=( (1<<bits) - 1 );
              n &=( (1<<bits) - 1 );
							if(n<m) swap(m, n);
            }
        }
        return result;
    }
};
