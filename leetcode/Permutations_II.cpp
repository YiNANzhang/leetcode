class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > ret;
        sort(num.begin(), num.end());
        ret.push_back(num);
        while(nextPermute(num.begin(), num.end())){
            ret.push_back(num);
        }
        return ret;
    }
    
    template<typename BidiIt>
    bool nextPermute(BidiIt begin,BidiIt end){
        const auto rfirst = reverse_iterator<BidiIt>(end);
        const auto rlast = reverse_iterator<BidiIt>(begin);
        auto pivot = next(rfirst);
        while(pivot!=rlast && *pivot >= *prev(pivot)){
            ++pivot;
        }
        if(pivot == rlast){ reverse(rfirst, rlast); return false; }
        auto change = find_if(rfirst, pivot, bind1st(less<int>(), *pivot));
        swap(*pivot, *change);
        reverse(rfirst, pivot);
        return true;
    }
};
