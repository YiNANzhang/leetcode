class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        bool used[9];
        for(int i=0;i<9;i++){
            fill(used, used+9, false);
            for(int j=0;j<9;j++){
                if(!check(board[i][j], used))
                    return false;
            }
            
            fill(used,used+9, false);
            for(int j=0;j<9;j++){
                if(!check(board[j][i], used))
                    return false;
            }
        }
        
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++){
                fill(used, used+9, false);
                for(int ii=i*3;ii<i*3+3;ii++)
                    for(int jj=j*3;jj<j*3+3;jj++)
                        if(!check(board[ii][jj], used))
                            return false;
            }
        return true;
    }
    
    bool check(char ch, bool used[]){
        if(ch == '.') return true;
        if(used[ch-'1']==true) return false;
        used[ch-'1'] = true;
        return true;
    }
};
