class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> res;
        //unordered_map<int, int> map;
        vector<vector<int> > graph(numCourses);
        queue<int> zero_in;
        for (auto it : prerequisites) {
            graph[it.second].push_back(it.first);
        }
        
        int indegree[numCourses] = {0}; 
        for (int i = 0; i < graph.size(); ++i) {
            for (int j = 0; j < graph[i].size(); ++j) {
                indegree[graph[i][j]]++;
            }
        }
        
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) zero_in.push(i);
        }
        
        //dfs(zero_in, res, graph);
        int count = 0;
        while(!zero_in.empty()) {
            int node = zero_in.front();
            res.push_back(node);
            zero_in.pop();
            count++;
            for (int i = 0; i < graph[node].size(); ++i) {
                if (--indegree[graph[node][i]] == 0) zero_in.push(graph[node][i]);
            }
        }
        if (count != numCourses) return vector<int>();
        return res;
    }

};
