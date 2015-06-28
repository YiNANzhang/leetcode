class Solution {
public:
    int findMin(vector<int> &num) {
        if(num.empty()) return -1;
        //int pivot = num[0];
        for(size_t i = 1;i<num.size();i++){
            if(num[i]<num[0])
                return num[i];
        }
        return num[0];
    }
};
