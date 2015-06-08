class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > ret(n, vector<int>(n, 0));
        int i = 0;
        int beginx = 0, endx = n - 1;
        int beginy = 0, endy = n - 1;
        while(true) {
            for(int j = beginx; j <= endx; j++) ret[beginy][j] = ++i;
            if(++beginy > endy) break;
            for(int j = beginy; j <= endy; j++) ret[j][endx] = ++i;
            if(--endx < beginx) break;
            for(int j = endx; j >= beginx; --j) ret[endy][j] = ++i;
            if(--endy < beginy) break;
            for(int j = endy; j >=beginy; --j) ret[j][beginx] = ++i;
            if(++beginx > endx) break;
        }
        return ret;
    }
};
