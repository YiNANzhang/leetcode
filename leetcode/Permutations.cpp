class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;
        if(num.size()==0) return result;
        if(num.size()==1){
            result.push_back(num);
            return result;
        }
        int insert = num.back();
        num.pop_back();
        result = permute(num);
        vector<vector<int> > ret;
        for(int i=0;i<result.size();i++){
            for(int j=0;j<=result[i].size();j++){
                vector<int> tmp = result[i];
                auto p = tmp.begin();
                if(j==result[i].size()){
                    tmp.push_back(insert);
                    ret.push_back(tmp);
                }else{
                    tmp.insert(p+j, insert);
                    ret.push_back(tmp);
                }
            }
        }
        return ret;
    }
};
