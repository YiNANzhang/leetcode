class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int > hsh;
		for(int i = 0; i < nums.size(); ++i) {
			if(hsh.find(nums[i]) == hsh.end()) hsh.insert(make_pair(nums[i], i));
			else {
				int diff = i - hsh[nums[i]];
				if(diff <= k) return true;
				hsh[nums[i]] = i;
			}
		} 
		return false;
    }
};
