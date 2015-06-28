class Solution {
private:
    int max_product;
public:
    int max(int x,int y,int z){
        int max;
        max = x>y?x:y;
        max = max>z?max:z;
        return max;
    }
    int min(int x,int y,int z){
        int min;
        min = x<y?x:y;
        min = min<z?min:z;
        return min;
    }
    int maxProduct(int A[], int n) {
        if(n<1){
            return 0;
        }
        int min_temp=A[0];
        int max_temp=A[0];
        max_product=A[0];
        for(int i=1;i<n;i++){
            int a = min_temp*A[i];
            int b = max_temp*A[i];
            int c = A[i];
            max_temp=max(a,b,c);
            min_temp=min(a,b,c);
            max_product = max_product>max_temp?max_product:max_temp;
        }
        return max_product;
    }
};
