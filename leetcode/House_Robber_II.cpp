class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        int n = nums.size();
        int val1 = 0, val2 = 0;
        int cur1 = 0, pre1 = 0; 
        for(int i = 0; i < n-1; ++i){
            cur1 = max(nums[i]+cur1, pre1);
            swap(cur1, pre1);
        }
        val1 = max(pre1, cur1);
        int cur2 = 0, pre2 = 0;
        for(int j = 1; j < n; ++j){
            cur2 = max(nums[j]+cur2, pre2);
            swap(cur2, pre2);
        }
        val2 = max(pre2, cur2);
        return max(val1, val2);
    }
};
