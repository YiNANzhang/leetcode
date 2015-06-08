class Solution {
    //vector<int> table;
public:
    int numTrees(int n) {
        if(n<=2) return n;
        int ret=0;
        for(int i=1;i<=n;i++){
            if(i ==1 || i==n) ret+=numTrees(n-1);
            ret += numTrees(i-1)*numTrees(n-i);
        }
        return ret;
    }
};
