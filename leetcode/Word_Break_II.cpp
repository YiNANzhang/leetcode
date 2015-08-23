class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        int n = s.size();
        vector<vector<bool> > f(n+1, vector<bool>(n, false));
        
        vector<string> ret;
        vector<string> temp;
        for(int i=1;i<=n;++i){
            for(int j=i-1;j>=0;--j){
                if(!f[i][j] && dict.find(s.substr(j, i-j))!=dict.end())
                    f[i][j] = true;
            }
        }
        DFS(s, s.size(), ret, f, temp);
        return ret;
    }
    
private:
    void DFS(const string s,  int cur, 
        vector<string> &ret, const vector<vector<bool> > &f, vector<string> &path){
        if(cur == 0){
            string tmp;
            tmp = path[0];
            for(auto it=++path.rbegin();it!=path.rend();++it){
                tmp+=" " + *it;
            }
            ret.push_back(tmp);
        }
        for(int i=0;i<s.size();++i){
            if(f[cur][i]){
                path.push_back(s.substr(i, cur-i));
                DFS(s, i, ret, f, path);
                path.pop_back();
            }
        }
    }
};
