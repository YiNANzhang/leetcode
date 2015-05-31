class Solution {
public:
    int trap(int A[], int n) {
        if(n==0) return 0;
        int water=0,maxpos=0,maxval;
        maxval=A[0];
        for(int i=1;i<n;++i){
            int pivot=min(A[i],maxval);
            for(int j=i-1;j>maxpos;--j){
                if(A[j]>=pivot)
                    break;
                water+=(pivot-A[j]);
                A[j]=pivot;
            }
            maxval = max(A[i], maxval);
            maxpos = (A[i]>=maxval)?i:maxpos;
        }
        return water;
    }
};
