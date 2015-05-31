class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if((m+n)%2==1)
            return findMedianSortedArrays(nums1, m, nums2, n, (m+n)/2+1);
        else{
            return (double)(findMedianSortedArrays(nums1, m, nums2, n, (m+n)/2) 
                    + findMedianSortedArrays(nums1, m, nums2, n, (m+n)/2+1) )/2.0;
        }
    }
    
private:    
    static int findMedianSortedArrays(vector<int> &A, int m, vector<int> &B, int n, int k){
        if(m > n) return findMedianSortedArrays(B, n, A, m, k);
        int start = 0, end = m;
        while(start < end) {
            int mid = start + (end - start) / 2, j = k - 1 - mid;
            if(j >= n || A[mid] < B[j]) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        int Ai = start - 1 >=0 ? A[start-1] : INT_MIN;
        int Bj = k - 1 - start >= 0 ? B[k-1-start] : INT_MIN;
        return max(Ai, Bj);
    }
};
