class Solution {
public:
    int trailingZeroes(int n) {
        int f=5;
        int quo=n/f;
        int sum=0;
        while(quo>0){
            sum+=quo;
            f*=5;
            quo=n/f;
        }
        return sum;
    }
};
