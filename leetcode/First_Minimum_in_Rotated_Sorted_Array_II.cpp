class Solution {
public:
    int findMin(vector<int> &num) {
        for(unsigned i=1;i<num.size();i++){
            if(num[i]<num[i-1])
                return num[i];
        }
        return num[0];
    }
};
