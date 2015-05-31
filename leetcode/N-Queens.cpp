class Solution {
    vector<bool> col;
    vector<bool> main_diag;
    vector<bool> anti_diag;
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > ret;
        //for(int i = 0; i < n; ++i) {
        //vector<vector<string> > tmp;
        //vector<struct xy> path;
        this->col = vector<bool>(n, false);
        this->main_diag = vector<bool>(2*n-1, false);
        this->anti_diag = vector<bool>(2*n-1, false);
        vector<int> C(n, 0);
        dfs(ret, C, 0);
        //for(auto i : tmp) {
            //ret.push_back(tmp);
        //}
        return ret;
    }
    void dfs(vector<vector<string> > &ret, vector<int> C, int row) {
        int n = C.size();
        if(row == n) {
            vector<string> tmp;
            for(int i = 0; i < n; ++i) {
                string str(n, '.');
                str[C[i]] = 'Q';
                tmp.push_back(str);
            }
            ret.push_back(tmp);
            return;
        }
        for(int j = 0; j < n; ++j) {
            bool ok = !col[j] && !main_diag[j+row] && !anti_diag[row-j+n-1];
            if(!ok) continue;
            C[row] = j; 
            col[j] = main_diag[j+row] = anti_diag[row-j+n-1] = true;
            dfs(ret, C, row+1);
            col[j] = main_diag[j+row] = anti_diag[row-j+n-1] = false;
        }
        
    }
};
