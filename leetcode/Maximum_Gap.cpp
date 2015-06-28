class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        int max_val = -1;
        int min_val = INT_MAX;
        // 求最大值，最小值，可以采用更优秀的方法
        for(int i = 0; i < nums.size(); ++i) {
            max_val = nums[i] > max_val ? nums[i] : max_val;
            min_val = nums[i] < min_val ? nums[i] : min_val;
        }
        
        int gap = (max_val - min_val) / nums.size() + 1;
        vector<vector<int> > buckets(nums.size()+1);
        for(int i = 0; i < nums.size(); ++i) {
            int j = (nums[i] - min_val) / gap;
            buckets[j].push_back(nums[i]);
        }
        int pre_max = -1;
        int cur_min = INT_MAX;
        int cur_max = -1;
        //int pre_min = INT_MAX;
        int max_gap = -1;
        for(int i = 0; i < buckets.size(); ++i) {
            cur_max = -1;
            cur_min = INT_MAX;
            if(buckets[i].empty()) continue;
            for(int j = 0; j < buckets[i].size(); ++j) {
                cur_min = (buckets[i][j] < cur_min) ? buckets[i][j] : cur_min;
                cur_max = (buckets[i][j] > cur_max) ? buckets[i][j] : cur_max;
            }
            if(i > 0) {
                max_gap = (cur_min - pre_max) > max_gap ? (cur_min - pre_max) : max_gap;
            }
            pre_max = cur_max;
        }
        return max_gap;
        
    }
    
};
