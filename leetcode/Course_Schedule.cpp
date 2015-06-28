class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if(numCourses == 0) return true;
        stack<int> zero_in;
        vector<vector<int> > graph(numCourses);
        for(int i = 0; i < prerequisites.size(); ++i) {
            graph[prerequisites[i].first].push_back(prerequisites[i].second);
        }
        
        int indegree[numCourses] = {0};
        
        for(int i = 0; i < graph.size(); ++i) {
            for(int j = 0; j < graph[i].size(); ++j) {
                indegree[graph[i][j]]++;
            }
        //     indegree[i] = graph[i].size();
        }
        
        for(int i = 0; i < numCourses; ++i) {
            if(indegree[i] == 0) zero_in.push(i);
        }
        int count = 0;
        while(!zero_in.empty()) {
            int index = zero_in.top();
            zero_in.pop();
            count++;
            for(int i = 0; i < graph[index].size(); ++ i) {
                if(--indegree[graph[index][i]] == 0) zero_in.push(graph[index][i]);
            }
        }
        return count == numCourses;
    }
};
