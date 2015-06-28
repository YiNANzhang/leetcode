class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return findKthLargest(nums, 0, n, k-1);
    }
    
    int findKthLargest(vector<int>& nums, int begin, int end, int k) {
        int index = partition(nums, begin, end);
        if(index == k) return nums[k];
        if(index < k) return findKthLargest(nums, index+1, end, k);
        return findKthLargest(nums, begin, index, k);
    }
    
    int partition(vector<int> &nums, int begin, int end) {
        int pivot = nums[begin];
        int n = nums.size();
        int i = begin;
        for(int j = begin+1; j < end; ++j) {
            if(pivot < nums[j]) {
                int temp = nums[i+1];
                nums[i+1] = nums[j];
                nums[j] = temp;
                ++i;
            }
        }
        nums[begin] = nums[i];
        nums[i] = pivot;
        return i;
    }
};
