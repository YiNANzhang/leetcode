class Solution {
public:
    string longestPrefix(string s1,string s2){
        size_t i=0;
        while(s1[i]!=std::string::npos && s2[i]!=std::string::npos){
            if(s1[i]!=s2[i]){
                return s1.substr(0,i);
            }
            i++;
        }
        return s1.size()<s2.size()?s1:s2;
    }
    
    string longestCommonPrefix(vector<string> &strs) {
        if(strs.empty()) return "";
        string result = strs[0];
        for(size_t i=1;i<strs.size();i++){
            result = longestPrefix(result,strs[i]);
        }
        return result;
    }
};
