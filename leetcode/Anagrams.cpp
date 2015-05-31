class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > groups;
        vector<string> ret;
        for(int i = 0; i < strs.size(); ++i) {
            string str = strs[i];
            sort(str.begin(), str.end());
            groups[str].push_back(strs[i]);
        }
        
        for(auto it = groups.begin(); it != groups.end(); ++it) {
            if((it->second).size() > 1) ret.insert(ret.end(), (it->second).begin(), (it->second).end());
        }
        return ret;
    }
};
