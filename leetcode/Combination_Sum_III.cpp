class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > ret;
        if(k*(k+1)/2 > n) return ret;
        vector<int> path;
        dfs(ret, path, k, 1, n);
        return ret;
    }
    
    void dfs(vector<vector<int> > &ret, vector<int> &path, int k, int i, int re){
        if(re == 0 && k == path.size()) {
            ret.push_back(path);
            return;
        }
        if(re < 0) return;
        else {
            if(path.size() >= k) return;
            //if(i == n) return;
            for(int j = i; j <= re && j <=9; j++) {
                path.push_back(j);
                dfs(ret, path, k, j+1, re-j);
                path.pop_back();
            }
        }
    }
};
