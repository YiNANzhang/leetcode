class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int result;
        int min_gap = INT_MAX;
        sort(num.begin(),num.end());
        vector<int>::iterator last = num.end();
        for(auto a=num.begin();a<prev(last,2);a++){
            auto b = next(a);
            auto c = prev(last);
            while(b<c){
                const int sum = *a+*b+*c;
                if(sum > target){
                    --c;
                }else{
                    ++b;
                }
                const int gap = abs(sum - target);
                if(gap<min_gap){
                    min_gap = gap;
                    result = sum;
                }
            }
        }
        return result;
    }
};
