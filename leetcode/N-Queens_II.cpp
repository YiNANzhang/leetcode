class Solution {
    int totalNum;
    vector<bool> col;
    vector<bool> main_diag;
    vector<bool> anti_diag;
public:
    int totalNQueens(int n) {
        totalNum = 0;
        this->col = vector<bool>(n, false);
        this->main_diag = vector<bool>(2*n-1, false);
        this->anti_diag = vector<bool>(2*n-1, false);
        dfs(n, 0);
        return totalNum;
    }
    
    void dfs(int n, int row) {
        if(row == n) {
            totalNum++;
            return;
        }
        for(int i = 0; i < n; ++i) {
            bool ok = col[i] || main_diag[i+row] || anti_diag[row-i+n-1];
            if(ok) continue;
            col[i] = main_diag[i+row] = anti_diag[row-i+n-1] = true;
            dfs(n, row+1);
            col[i] = main_diag[i+row] = anti_diag[row-i+n-1] = false;            
        }
    }
};
