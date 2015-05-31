class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int elen=0;
        for(int i=0;i<n-elen;){
            if(A[i] == elem){
                int temp = A[n-1-elen];
                A[n-1-elen]=A[i];
                A[i] = temp;
                elen++;
            }
            else
                i++;
        }
        return n-elen;
    }
};
