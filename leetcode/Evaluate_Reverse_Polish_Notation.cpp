class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        //int ret = 0;
        vector<int> stck;
        for(int i = 0; i < tokens.size(); ++i) {
            int v = 0, l = 0, r = 0;
            if(tokens[i] == "+") { 
                r = stck.back();
                stck.pop_back();
                l = stck.back();
                stck.pop_back();
                v = l + r;
                stck.push_back(v);
            }
            else if(tokens[i] == "-") {
                r = stck.back();
                stck.pop_back();
                l = stck.back();
                stck.pop_back();
                v = l - r;
                stck.push_back(v);
            }
            else if(tokens[i] == "*") {
                r = stck.back();
                stck.pop_back();
                l = stck.back();
                stck.pop_back();
                v = l * r;
                stck.push_back(v);
            }
            else if(tokens[i] == "/") {
                r = stck.back();
                stck.pop_back();
                l = stck.back();
                stck.pop_back();
                v = l / r;
                stck.push_back(v);
            }
            else {
                v = stoi(tokens[i]);
                stck.push_back(v);
            }
        }
        return stck.back();
    }
};
