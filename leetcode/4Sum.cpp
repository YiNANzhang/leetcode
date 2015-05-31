class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > res;
        int n = num.size();
        if( n<4 ) return res;
        sort(num.begin(), num.end());
        unordered_map<int, vector<pair<int,int> > > cache;
        for(size_t i=0;i<n-3;i++){
            for(size_t j=i+1;j<n-2;j++){
                cache[num[i]+num[j]].push_back(pair<int, int>(i,j));
            }
        }
        
        for(size_t b=2;b<n-1;b++){
            for(size_t c=b+1;c<n;c++){
                const int key = target-num[b]-num[c];
                if(cache.find(key) == cache.end())
                    continue;
                const auto &vec = cache[key];
                for(size_t k=0;k<vec.size();k++){
                    if(b<=vec[k].second)
                        continue;
                    res.push_back({num[vec[k].first],num[vec[k].second],num[b],num[c]});
                }
            }
        }
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};
