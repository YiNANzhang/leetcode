class Solution {
public:
    void rotate(int nums[], int n, int k) {
        if(k<0) return;
        k=k%n;
        ReverseArray(nums, n-k);
        ReverseArray(nums+n-k, k);
        ReverseArray(nums, n);
    }
    
    void ReverseArray(int array[] , int b){
        for(int a=0; a<--b; a++){
            int temp = array[b];
            array[b] = array[a];
            array[a] = temp;
        }
    }
};
