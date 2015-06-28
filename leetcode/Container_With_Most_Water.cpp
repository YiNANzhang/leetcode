class Solution {
public:
    int maxArea(vector<int> &height) {
        int i, j;
        int area=0, max_area=0;
        for(i=0,j=height.size()-1;i<j;){
            area = min(height[i], height[j]) * (j-i);
            max_area = max(area, max_area);
            if(height[i]<=height[j]){
                ++i;
            }else{
                --j;
            }
        }
        return max_area;
    }
};
