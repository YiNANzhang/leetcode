class Solution {
public:
    bool canJump(vector<int>& nums) {
        int index = 1;
        int n = nums.size();
        for(int i=0; i < index && index<n;++i) {
            index = max(index,1+nums[i]+i);
        }
		return index >= n;
		
    }
};
