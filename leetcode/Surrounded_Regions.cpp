class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int, int> > q;
        if (board.empty()) return;
        int rown = board.size();
        int coln = board[0].size();
        for (int i = 0; i < rown; ++i) {
            if (board[i][0] == 'O') {
                q.push(make_pair(i, 0));
                board[i][0] = '#';
            }
            if (board[i][coln-1] == 'O') {
                q.push(make_pair(i, coln-1));
                board[i][coln-1] = '#';
            }
        }
        
        for (int i = 0; i < coln; ++i) {
            if (board[0][i] == 'O') {
                q.push(make_pair(0, i));
                board[0][i] = '#';
            }
            if (board[rown-1][i] == 'O') {
                q.push(make_pair(rown-1, i));
                board[rown-1][i] = '#';
            }
        }
        
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if (x-1 > 0 && board[x-1][y] == 'O') { q.push(make_pair(x-1, y)); board[x-1][y] = '#'; }
            if (x+1 < rown && board[x+1][y] == 'O') { q.push(make_pair(x+1, y)); board[x+1][y] = '#'; }
            if (y-1 > 0 && board[x][y-1] == 'O') { q.push(make_pair(x, y-1)); board[x][y-1] = '#'; }
            if (y+1 < coln && board[x][y+1] == 'O') { q.push(make_pair(x, y+1)); board[x][y+1] = '#'; }
        }
        
        for (int i = 0; i < rown; ++i) {
            for (int j = 0; j < coln; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};
