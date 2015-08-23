class Solution {
public:
    int calculate(string s) {
        //if (isdigit(s)) return stoi(s);
		vector<int> nums;
		vector<char> ops;
		int val = 0;
		//char op;
		int lvalue, rvalue;
		//int res;
		for (int i = 0; i < s.size();++i) {
			val = 0;

			if (s[i] == ' ') {
				continue;				
			} else if (s[i] == '(' || s[i] == '+' || s[i] == '-') {
				ops.push_back(s[i]);
				continue;
			} else if (s[i] == ')' ) {
				ops.pop_back();
			} else {
				while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
					val = val*10 + s[i++] - '0';
				}
				nums.push_back(val);
				--i;
			}
			if (!ops.empty() && ops.back() != '(' && nums.size() > 1) {
				rvalue = nums.back();
				nums.pop_back();
				lvalue = nums.back();
				nums.pop_back();
				if (ops.back() == '+') val = lvalue + rvalue;
				else if (ops.back() == '-') val = lvalue - rvalue;
				nums.push_back(val);
				ops.pop_back();
			} 
		}   
		if (nums.empty()) return 0;
		return nums[0]; 
    }
};
