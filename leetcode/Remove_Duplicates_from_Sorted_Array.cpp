class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int newp,i;
        if(n==0) return 0;
        newp=0;
        for(i=1;i<n;i++){
            if(A[newp]!=A[i])
                A[++newp] = A[i];
        }
        return newp+1;
    }
};
