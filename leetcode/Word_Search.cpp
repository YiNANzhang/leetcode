class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.empty()) return true;
		if(board.empty()) return false;
		int row = board.size();
		int col = board[0].size();
		//vector<vector<bool> > visited(row, vector<bool>(col));
		//fill_n(&visited[0][0], row*col, false);
		//bool ret;
		for(int i = 0; i < row; i++) {
			for(int j = 0; j < col; j++) {
				if(dfs(board, word, 0/*, visited*/, i, j))
					return true;
			}
		}
		return false;
    }

	bool dfs(vector<vector<char> > &board, string word, int i, /*vector<vector<bool> > visited, */int r, int c) {
		if(i == word.size()) return true;
		if(r < 0 || r > board.size()-1 || c < 0 || c > board[0].size()-1) return false;
		if(board[r][c] != word[i]) return false;
		if(board[r][c] == '#') return false;
		char tmp = board[r][c];
		board[r][c] = '#';
		bool ret = dfs(board, word, i+1/*, visited*/, r-1, c) ||
				   dfs(board, word, i+1/*, visited*/, r+1, c) ||
				   dfs(board, word, i+1/*, visited*/, r, c-1) ||
				   dfs(board, word, i+1/*, visited*/, r, c+1);
		board[r][c] = tmp;
		return ret;
	}
};
