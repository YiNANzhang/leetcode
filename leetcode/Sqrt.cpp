class Solution {
public:
    int mySqrt(int x) {
        int begin = 1, end = x/2;
        if(x < 2) return x;
        int ret = 0;
        while(begin<=end){
            int mid = begin + (end-begin)/2;
            if(x/mid > mid) {
                begin = mid+1;
                ret = mid;
            }else if(x/mid < mid) {
                end = mid-1;
            }else
                return mid;
        }
        return ret;
    }
};
