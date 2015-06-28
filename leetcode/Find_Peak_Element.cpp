class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int num_size=num.size();
        if(num_size < 2) return num_size-1;
        if(num_size ==2) return num[0]>num[1]?0:1;
        for(unsigned i=1; i<num_size-1;i++ ){
            if(num[i]>num[i-1] && num[i]>num[i+1])
                return i;
        }
        return num[0]>num[num_size-1]?0:num_size-1;
    }
};
