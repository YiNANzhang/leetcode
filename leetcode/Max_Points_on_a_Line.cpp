/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if(points.size() < 3) return points.size();
        int ret = 2;
        
        int n = points.size();
        unordered_map<double, int> hsh;
        int samePointsNum;
        int count;
        double k;
        for(int i = 0; i < n; ++i) {
            count = 1;
            samePointsNum = 0;
            for(int j = i + 1; j < n; ++j) {
                if(points[j].x == points[i].x) {
                    k = INFINITY;
                    if(points[j].y == points[i].y) {
                        ++samePointsNum;
                        continue;
                    }
                } else {
                    k = (double)(points[j].y - points[i].y) / (double)(points[j].x - points[i].x);
                }
                if(hsh.find(k) != hsh.end()) hsh[k]++;
                else {
                    hsh.insert(make_pair(k, 2));
                }
                count = hsh[k] > count ? hsh[k] : count;
            }
            ret = max(ret, samePointsNum + count);
            hsh.clear();

        }
        return ret;
    }
};
