class Solution {
public:
    int countPrimes(int n) {
        if(n < 3) return 0;
        int count = n-2;
        bool prime[n];
        fill(prime, prime+n, true);
        int m = sqrt(n);
        for(int i = 2; i <= m; i++) {
            //int m = sqrt(n);
            for(int j = 2; j * i < n ; ++j) {
                if(prime[i*j]) {
                    prime[i*j] = false;
                    count--;
                }
            }
        }
        return count;
    }
};
