class Solution {
public:
    int calculate(string s) {
		vector<int> nums;
		vector<char> ops;
		int num = 0, ans = 0, sign = 1;
		for (int i = 0; i < s.size(); ++i) {
			num = 0;
			if (s[i] == ' ') {
				continue;
			}
			else if (s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '-') {
				ops.push_back(s[i]);
				continue;
			} else {
				while (i < s.size() && s[i] >= '0' && s[i] <= '9')
					num = num*10 + s[i++] - '0';
				nums.push_back(num);
				--i;
			}
			if (!ops.empty() && (ops.back() == '*' || ops.back() == '/') && nums.size() > 1) {
				int rvalue, lvalue;
				rvalue = nums.back();
				nums.pop_back();
				lvalue = nums.back();
				nums.pop_back();
				if (ops.back() == '*') num = lvalue * rvalue;
				else if (ops.back() == '/') num = lvalue / rvalue;
				nums.push_back(num);
				ops.pop_back();
				num = 0;
			}
		}
		if (nums.empty()) return 0;
		ans = nums[0];
		for (int i = 1; i < nums.size(); ++i) {
			sign = ops[i-1] == '+' ? 1 : -1;
			ans = ans + nums[i]*sign;
		}		
		return ans;
    }

};
