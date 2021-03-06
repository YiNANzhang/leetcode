class Solution {
public:
    int search(int A[], int n, int target) {
        int first = 0;
        int last  = n;
        while(first<last){
            int mid = (first+last)/2;
            if(A[mid] == target)
                return mid;
            if(A[first]<A[mid]){
                if(A[first]<=target && A[mid]>target){
                    last = mid;
                }else{
                    first = ++mid;
                }
            }else{
                if(A[mid]<target && A[last-1]>=target){
                    first = ++mid;
                }else{
                    last = mid;
                }
            }
        }
        return -1;
    }
};
