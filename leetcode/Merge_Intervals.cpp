/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start || (a.start == b.start && a.end < b.end);
        });
        vector<Interval> ret;
        if(!intervals.empty()) ret.push_back(intervals[0]);
        int i;
        for (i=1; i<intervals.size(); i++) {
            if(intervals[i].start<=ret.back().end) {
                ret.back().end = max(intervals[i].end, ret.back().end);
            }else{
                ret.push_back(intervals[i]);
            }
        }
        return ret;
    }
};
