class Solution {
public:
    int jump(vector<int>& nums) {
    int n = nums.size();
		vector<int> step;
		step.push_back(0);
		for(int i = 0; i < n; ++i) {
			for(int j = step.size(); j <= i+nums[i] && j < n; ++j) {
				step.push_back(step[i]+1);
				if(j == n-1) return step[n-1];
			}
		}
		return step[n-1];
    }
};

