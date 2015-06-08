class Solution {
public:
    double pow(double x, int n) {
        if(n<0 && n!=INT_MIN) return 1.0/pow_1(x, -n);
        if(n==INT_MIN) return 1.0/(pow_1(x, INT_MAX)*x);
        return pow_1(x, n);
    }

    double pow_1(double x, int n){
        if(n==0) return 1.0;
        if(n==1) return x;
        double v = pow(x, n/2);
        return v*v*pow(x, n%2);
    }
};
