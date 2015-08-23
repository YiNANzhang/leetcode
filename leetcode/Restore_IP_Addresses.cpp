class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
		if (s.size() < 4 || s.size() > 12) return result;
		vector<int> path;
		dfs(result, path, 0, s);
		return result;
    }

	void dfs(vector<string> &result, vector<int> &path, int start, string &s) {
		if (path.size() >= 4 && start < s.size()) {
			return;
		}
		if (start == s.size() && path.size() == 4) {
			string tmp;
			for(int i = 0; i < path.size()-1; ++i) {
				tmp += to_string(path[i]);
				tmp += '.';
			}
			tmp += to_string(path.back());
			result.push_back(tmp);
			return;
		}
		int count = 1;
		if (s[start] == '0') {
			path.push_back(0);
			dfs(result, path, start + count, s);
			path.pop_back();
		}
		else {
			for (; count <=3 && start + count <= s.size(); ++count) {
				int m = stoi(s.substr(start, count));
				if(m <= 255 && m > 0) {
					path.push_back(m);
					dfs(result, path, start + count, s);
					path.pop_back();
				}
			}
		}
	}
};


