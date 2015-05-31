class Solution {
public:
    int longestValidParentheses(string s) {
        int result = 0;
        //int unmatched = 0;
        int cur_matched = -1;
        stack<int> stck;
        for(int i=0; i<s.size() ;++i) {
            if(stck.empty() && s[i] == ')') {
                cur_matched = i;
                continue;
            } else if(s[i] == ')') {
                int temp = stck.top();
                stck.pop();
                //cur_matched++;
                if(stck.empty()) {
                    result = max(i-cur_matched, result);
                    //cur_matched = i;
                } else {
                    //stck.push(i);
                    //cur_matched = 0;
                    result = max(result, i-stck.top());
                }
                //result = (unmatched == 0)?(result+cur_matched):max(result, cur_matched);
                //result = max(result, cur_matched);
            } else {
                stck.push(i);
            }
        }
        return result;
    }
};
