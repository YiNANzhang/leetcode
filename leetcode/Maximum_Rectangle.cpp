class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int r = matrix.size();
        int c = matrix[0].size();
        int ret = 0;
        int left[c], right[c], height[c];
        fill_n(left, c,0);
        fill_n(right, c, c);
        fill_n(height, c, 0);
        
        for(int i=0; i<r; ++i) {
            int cur_left=0, cur_right=c;
            for(int j=0; j<c; ++j) {
                if(matrix[i][j] == '1'){
                    height[j]++;
                    left[j] = max(left[j], cur_left);
                }else{
                    height[j]=0;
                    left[j]=0;
                    cur_left = j+1;
                }
            }
            
            for(int j=c-1; j>=0; --j){
                if(matrix[i][j] == '1') {
                    right[j] = min(right[j], cur_right);
                    ret = max(ret, height[j]*(right[j]-left[j]));
                }else{
                    right[j]=c;
                    cur_right=j;
                }
            }
        }
        return ret;
    }
};
