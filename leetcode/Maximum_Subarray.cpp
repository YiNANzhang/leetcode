class Solution {
public:
    int maxSubArray(int A[], int n) {
        int sum=A[0];
        int max=sum;
        for(unsigned i=1;i<n;i++){
            sum += A[i];
            if(sum<A[i]){
                sum = A[i];
            }
            max=max<sum?sum:max;
        }
        return max;
    }
};
