class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, int> map;
        int result = 1;
        for(int i=0;i<num.size();++i) {
            if(map.find(num[i]) == map.end()) {
                map[num[i]] = 1;
                int right = map.find(num[i] + 1) != map.end() ? (num[i] + map[num[i]+1]) : num[i];
                int left = map.find(num[i] - 1) != map.end() ? (num[i] - map[num[i]-1]) : num[i];
                int length = right - left + 1;
                map[left] = map[right] = length;
                result = max(result, length);   
            }
        }
        return result;
    }
};
