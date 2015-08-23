class Solution {
    public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
		int candidate[2];
		int nTimes[2] = {0};
		
		for (int i = 0; i < n; ++i) {		
			int j = 0;
			for (; j < 2; ++j) {
				if (nTimes[j] == 0) {
					if (candidate[1-j] == nums[i]) {
						nTimes[1-j]++;
					} else {
						candidate[j] = nums[i];
						nTimes[j]++;
					}
					break;
				}	
			}
			if (j == 2) {
				if (candidate[0] == nums[i]) nTimes[0]++;
				else if (candidate[1] == nums[i]) nTimes[1]++;
				else {
					nTimes[0]--;
					nTimes[1]--;
				}
			}
		}
		vector<int> res;
		int candidate1_num = 0, candidate2_num = 0;
		for (auto it : nums) {
			if (it == candidate[0]) candidate1_num++;
			else if (it == candidate[1]) candidate2_num++;
		}
		if (candidate1_num > n/3) res.push_back(candidate[0]);
		if (candidate2_num > n/3) res.push_back(candidate[1]);
		return res; 
    }
};

