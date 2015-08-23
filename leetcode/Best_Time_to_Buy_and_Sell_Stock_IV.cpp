#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

//bool cmp(unordered_multimap::iterator a, unordered_multimap::iterator b) return a.first < b.first;

class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		if (k == 0) return 0;
		unordered_multimap<int, pair<int, int>> map(k);
		int begin = 0, diff = 0, end; 
		for (end = 1; end < prices.size(); ++end) {
			if (prices[end] < prices[end-1] && end > begin) {
				if (end-1 > begin) {
					diff = prices[end-1] - prices[begin];
					map.insert(make_pair(diff, make_pair(begin, end)));
					diff = 0;
				}
				begin = end;
			}
		}
		if (end-1 > begin) map.insert(make_pair(prices[end-1]-prices[begin], make_pair(begin, end)));
		
		int result = 0;
		if (map.size() <= k) {
			for (auto it : map) {
				result += it.first;
			}
		} else {
			vector<int> temp;
			for (auto it : map) {
				temp.push_back(it.first);
			}
			sort(temp.begin(), temp.end());
			for (int i = temp.size()-1; i >= temp.size()-k; --i)
				result += temp[i];	
		}
		return result;
  }
};

int main() {
	int result;
	vector<int> prices({1,2,3,2,1,0,4,5});
	Solution sl;
	cout << sl.maxProfit(1, prices) << endl;
	return 0;
}
