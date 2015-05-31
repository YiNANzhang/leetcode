class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        int rever_n = 0;
        int i = n;
        string str;
        generateParenthesis(ret, str, 2*n, i, rever_n, 0);
        return ret;
    }
    
    void generateParenthesis(vector<string> &ret, string str, int n, int i, int rever_n, int num){
        if(num ==n){
            ret.push_back(str);
            return;
        }
        if(i==0){
            for(int j=0;j<rever_n;j++){
                str+=')';
            }
            ret.push_back(str);
            return;
        }
        if(rever_n==0){
            str+='(';
            generateParenthesis(ret, str, n, i-1, rever_n+1, num+1);
            return;
        }
        str+='(';
        generateParenthesis(ret, str, n, i-1, rever_n+1, num+1);
        str.pop_back();
        str+=')';
        generateParenthesis(ret, str, n, i, rever_n-1, num+1);
    }
};
