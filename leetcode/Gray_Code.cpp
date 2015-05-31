class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        int code = 0;
        int count = 0;
        result.push_back(code);
        for(unsigned i=0;i<n;i++){
            count = 0;
            while(count<pow(2,i)){
                int index = pow(2,i)-count;
                code = (1<<i) ^ result[index-1];
                result.push_back(code);
                count++;
            }
        }
        return result;
    }
};
