class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> res;
        priority_queue<pair<int, int>> curBuilds;
        int num = buildings.size();
        int curNum = 0;
        while (curNum < num || !curBuilds.empty()) {
            int cur_X = curBuilds.empty() ? buildings[curNum][0] : curBuilds.top().second;
            if (curNum >= num || cur_X < buildings[curNum][0]) {
                while (!curBuilds.empty() && cur_X >= curBuilds.top().second) {
                    curBuilds.pop();
                }
            } else {
                cur_X = buildings[curNum][0];
                while (curNum < num && cur_X == buildings[curNum][0]) {
                    curBuilds.push(make_pair(buildings[curNum][2], buildings[curNum][1]));
                    curNum++;
                }
            }
            int cur_H = curBuilds.empty() ? 0 : curBuilds.top().first;
            if (res.empty() || cur_H != res.back().second) res.push_back(make_pair(cur_X, cur_H));
        }
        return res;
    }
};
