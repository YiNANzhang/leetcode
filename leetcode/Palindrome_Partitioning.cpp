class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > result;
        vector<string> path;
        dfs(result, path, 0, s);
        return result;
    }
    
    void dfs(vector<vector<string> > &result, vector<string> &path, int start, string s) {
        if(start == s.size()) {
            result.push_back(path);
            return;
        }
        for(int i = start; i < s.size(); ++i) {
            if(isPalindrome(s, start, i) ){
                path.push_back(s.substr(start, i - start + 1));
                dfs(result, path, i+1, s);
                path.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s, int start, int end) {
        while(start < end) {
            if(s[start] != s[end])
                return false;
            ++start;
            --end;
        }
        return true;
    }
};
