class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        //if(height.empty()) return 0;
        stack<int> stck;
        height.push_back(0);
        int result = 0;
        for(int i=0; i<height.size();) {
            if(stck.empty() || height[i] > height[stck.top()]) stck.push(i++);
            else {
                int index = stck.top();
                stck.pop();
                result = max(result, height[index]*(stck.empty() ? i: i-stck.top()-1) );
            }
        }
        return result;
    }
};
