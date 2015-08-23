class Solution {
public:
	class Trie {
	public:
		Trie *children[26];
		bool 	leaf;
		int 	idx;
		Trie() {
			this->leaf = false;
			this->idx = -1;
			fill_n(this->children, 26, nullptr);
		}
	};
	
	void buildTrie(Trie *root, string word, int idx) {
		for (int i = 0; i < word.size(); ++i) {
			if (root->children[word[i]-'a'] == nullptr) {
				root->children[word[i]-'a'] = new Trie();
			}
			root = root->children[word[i]-'a'];
		}
		root->leaf = true;
		root->idx = idx;
	}
	
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		vector<string> res;
		if (words.empty() || board.empty()) return res;
		int row = board.size();
		int col = board[0].size();
		int wsize = words.size();
		
		Trie *root = new Trie();
		for (int i = 0; i < wsize; ++i) {
			buildTrie(root, words[i], i);
		}
		//buildTrie(root, )
		
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				findWord(res, board, root, row, col, i, j, words);
			}
		}
		return res;
	}
	
 	void findWord(vector<string>& res, vector<vector<char>>& board, Trie *root, int &row, int &col, int i, int j, vector<string>& words) {
		//if (i < 0 || i  > row-1 || j < 0 || j > col-1) return;
		if (board[i][j] == '#' || root->children[board[i][j]-'a'] == nullptr) return;
		char temp = board[i][j];
		board[i][j] = '#';
		if (root->children[temp-'a']->leaf) {
			res.push_back(words[root->children[temp-'a']->idx]);
			root->children[temp-'a']->leaf = false;
		}
		if (i > 0) findWord(res, board, root->children[temp-'a'], row, col, i-1, j, words);
		if (i < row-1) findWord(res, board, root->children[temp-'a'], row, col, i+1, j, words);
		if (j > 0) findWord(res, board, root->children[temp-'a'], row, col, i, j-1, words);
		if (j < col-1) findWord(res, board, root->children[temp-'a'], row, col, i, j+1, words);
		board[i][j] = temp;
	}

};
