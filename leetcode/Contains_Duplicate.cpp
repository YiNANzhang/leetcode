class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hset;
        for(int i = 0; i < nums.size(); ++i) {
            if(hset.count(nums[i]))
                return true;
            hset.insert(nums[i]);
        }
        return false;
    }
};
