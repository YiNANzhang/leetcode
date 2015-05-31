class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > result;
        if(num.size() < 3) return result;
        sort(num.begin(), num.end());
        //const int target = 0;
        int n = num.size();
        for(int i = 0; i < n-2; ++i) {
            if(i && num[i] == num[i-1]) continue;
            for(int j = i+1; j < n-1; ++j) {
                if((j > i+1) && num[j] == num[j-1]) continue;
                int k;
                for(k = n-1; k > j && (num[i]+num[j]+num[k]) > 0; --k) ;
                if(k>j && num[i] + num[j] + num[k] == 0)
                    result.push_back(vector<int>{num[i], num[j], num[k]});
            }
        }
        return result;
    }
};
