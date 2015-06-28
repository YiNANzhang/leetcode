class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int min_len = nums.size() + 1;
        int a = 0, b = -1;
        int sum = 0;
        while(b < (int)nums.size()) {
            if(sum < s) {
                b++;
                sum += nums[b];
            }else {
                min_len = min(min_len, b-a+1);
                sum -= nums[a];
                a++;
            }
        }
        return min_len == nums.size() + 1 ? 0 : min_len;
    }
};
