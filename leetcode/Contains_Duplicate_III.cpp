class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        queue<int> q;
        set<long long> map;
        //int l = 0;
        for(int i = 0; i < nums.size(); ++i) {
           if(q.size()>k){
               int num = q.front();
               q.pop();
               map.erase(num);
           }
           auto it = map.lower_bound((long long)nums[i]-(long long)t);
           if(it != map.end() && *it<=((long long)nums[i]+(long long)t)) return true;
           q.push(nums[i]);
           map.insert(nums[i]);
        }
        return false;
    }
};
