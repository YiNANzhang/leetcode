class Solution {
public:
    bool isHappy(int n) {
        set<int> path;
        return isHappy(path, n);
    }
    
    bool isHappy(set<int> &path, int n){
        int sum = 0;
        if( n == 1 ) return true;
        if(path.find(n) != path.end()) return false;
        path.insert(n);
        while(n) {
            sum += pow(n % 10 , 2);
            n = n / 10;
        }
        isHappy(path, sum);
    }
};
