class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        vector<int>::iterator it;
        int i;
        if(rowIndex == 0){
            result.push_back(1);
            return result;
        }
        result = getRow(rowIndex-1);
        for(i=0;i<rowIndex;i++){
            if(i==0)
                it = result.insert(result.begin(),1);
            else{
                int val = result[i]+result[i+1];
                *it = val;
            }
            it++;
        }
        return result;
    }
};
