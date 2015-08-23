class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> maxInWindow;
        vector<int> res;
        int n = nums.size();
        if (n < k || k <= 0) return res;
        for (int i = 0; i < k; ++i) {
            while (!maxInWindow.empty() && nums[maxInWindow.back()] < nums[i]) maxInWindow.pop_back();
            maxInWindow.push_back(i);
        }
        for (int i = k; i < n; ++i) {
            res.push_back(nums[maxInWindow.front()]);
            while (!maxInWindow.empty() && nums[maxInWindow.back()] < nums[i]) maxInWindow.pop_back();
            maxInWindow.push_back(i);
            if (maxInWindow.front() == i-k) maxInWindow.pop_front();
        }
        res.push_back(nums[maxInWindow.front()]);
        return res;
    }
};
