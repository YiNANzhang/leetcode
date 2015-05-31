class Solution {
private:
    int ret_value;
public:
    int singleNumber(int A[], int n) {
        if(n>0){
            ret_value = A[0];
            for(int i=1; i<n; i++){
                ret_value = ret_value^A[i];
            }
            return ret_value;
        }
        return -1;
    }
};
