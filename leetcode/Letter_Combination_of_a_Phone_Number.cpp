class Solution {

public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty() ) return vector<string>();
        char c[10][10] = {
			"",   		//0
			"",			//1	
			"abc",		//2
			"def",		//3
			"ghi",		//4
			"jkl",		//5
			"mno",		//6
			"pqrs",		//7
			"tuv",		//8
			"wxyz"		//9
		};
		int total[10] = {0, 0, 3, 3, 3, 3, 3, 4, 3, 4};
		int num = 1;
		int n = digits.size();
		//for (int i = 0; i < n; ++i) {
		//	num *= total[digits[i]-'0'];
		//}
		int answers[n];
		fill_n(answers, n, 0);
		vector<string> result;
		while (true) {
			string tmp = "";
			for (int i = 0; i < n; ++i) {
				//if(answers[i] >= 0)
				tmp += c[digits[i]-'0'][answers[i]];
			}
			result.push_back(tmp);
			int k = n-1;
			while (k >= 0) {
				if (answers[k] < total[digits[k]-'0']-1) {
					answers[k]++;
					break;
				} else {
					answers[k] = 0;
					k--; 
				}
			}
			if(k < 0)
				break;
		}
		return result;
    }
};

