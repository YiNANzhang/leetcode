class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        sort(A,A+n);
        for(int i=0;i<n;i++){
            if(A[i]<=0 || A[i] == i+1 || A[i]>n || A[i] == A[A[i]-1])
                continue;
            else{
                int temp = A[A[i]-1];
                A[A[i]-1] = A[i];
                A[i] = temp;
                i--;
            }
        }
        int i;
        for(i=0; i<n; i++){
            if(A[i]!=i+1)
                break;
        }
        return i+1;
    }
};
