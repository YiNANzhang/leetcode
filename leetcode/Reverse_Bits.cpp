class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t i = 1;
        uint32_t ret = 0;
        int j=0;
        while(j<31){
            ret |= i & n;
            ret *= 2;
            n /=2;
            j++;
        }
        ret += n;
        return ret;
    }
};
