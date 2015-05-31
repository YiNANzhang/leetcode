class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> result;
        map<int,int> hashtable;
        for(unsigned i=0;i<numbers.size();i++){
            hashtable[numbers[i]] = i;
        }
        for(unsigned j=0;j<numbers.size();j++){
            int gap = target - numbers[j];
            if(hashtable.find(gap) != hashtable.end() && hashtable[gap]>j){
                result.push_back(j+1);
                result.push_back(hashtable[gap]+1);
                break;
            }
        }
        return result;
    }
};
