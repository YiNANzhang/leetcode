class Solution {
public:
    int rob(vector<int> &num) {
        int prev = 0;
        int prev_prev = 0;

        for(int i=0;i<num.size();++i){
            int cur = num[i] + prev_prev;
            cur = max(prev, cur);
            prev_prev = prev;
            prev = cur;
        }
        return max(prev, prev_prev);
    }
};
