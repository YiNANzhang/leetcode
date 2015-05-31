class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int first = 0;
        int last = n;
        while(first<last){
            int mid = first + (last-first)/2;
            if(A[mid] == target){
                return mid;
            }else if(A[mid]<target){
                first = mid+1;
            }else{
                last = mid;
            }
        }
        return first;
    }
};
