class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if (nums.empty()) return result;
        int n = nums.size()-1;
        int begin = 0;
        for (int i = 0; i <= n; ++i) {
            if (((long long)nums[i+1] - (long long)nums[i]) > 1) {
                if (begin == i) result.push_back(to_string(nums[i]));
                else {
                string str = to_string(nums[begin]);
                str += "->";
                str += to_string(nums[i]);
                result.push_back(str);
                }
                begin = i+1;
            }
        }
        if (begin == n) {
            result.push_back(to_string(nums[n]));
        } else {
            string str = to_string(nums[begin]);
            str += "->";
            str += to_string(nums[n]);
            result.push_back(str);
        }
        return result;
    }
};
