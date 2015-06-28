class Solution {
public:
  vector<vector<int> > subsetsWithDup(vector<int> &S) {
	vector<vector<int> > result(1, vector<int>());
	sort(S.begin(), S.end());
	int count = 0;
	for (int i = 0; i < S.size(); i += count) {
		for (count = 0; count < S.size() && S[i] == S[i+count]; count++) {}
		vector<vector<int> > tmp = result;
		int tsize = tmp.size();
		for (int j = 0; j < count; ++j) {
			for (int t = 0; t < tsize; ++t) {
				tmp[t].push_back(S[i]);
			}
			//result.push_back(tmp);
			for(auto it : tmp) {
				result.push_back(it);
			}
		}
	}	
	return result;
  }
};

