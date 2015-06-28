bool cmp(const string a,const string b){
    return (a+b) > (b+a);
}

class Solution {
public:
    string largestNumber(vector<int> &num) {
        vector<string> str(num.size());
        stringstream stream;
        for(int i=0;i<num.size();++i){
            stream << num[i];
            stream >> str[i];
            stream.clear();
        }
        sort(str.begin(), str.end(), cmp);
        string ret;
        for(int i=0;i<str.size();++i){
            ret+=str[i];
        }
        int i;
        for(i=0;i<ret.size();++i){
            if(ret[i]!='0')
                break;
        }
        if(i==ret.size()) return "0";
        return ret.substr(i);
    }
};
