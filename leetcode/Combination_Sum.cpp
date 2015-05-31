class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > result;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        dfs(result, path, candidates, 0, target);
        return result;
    }
    
    bool dfs(vector<vector<int> > &result, vector<int> path, vector<int> &candidates, int start, int target) {
        if(0 == target) {
            result.push_back(path);
            return true;
        }
        
        if(target < candidates[start]) {
            return false;
        }
        for(int i = start; i < candidates.size(); ++i) {
            path.push_back(candidates[i]);
            dfs(result, path, candidates, i, target-candidates[i]);
            path.pop_back();
        }
    }
};
