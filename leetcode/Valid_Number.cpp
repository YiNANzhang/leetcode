class Solution {
public:
    bool isNumber(string s) {
        
        enum InputType {
            INVALID,
            DIGIT,
            SPACE,
            DOT,
            EXP,
            SIGNED,
            INPUT_NUM
        };
        const int state_table[][INPUT_NUM] = {
            -1, 1, 0, 2,-1, 3,
            -1, 1, 8, 4, 5,-1,
            -1, 4,-1,-1,-1,-1,
            -1, 1,-1, 2,-1,-1,
            -1, 4, 8,-1, 5,-1,
            -1, 7,-1,-1,-1, 6,
            -1, 7,-1,-1,-1,-1,
            -1, 7, 8,-1,-1,-1,
            -1,-1, 8,-1,-1,-1
        };
        int state = 0;
        for(int i=0;i<s.size();++i){
            InputType input_type = INVALID;
            if(s[i]==' ')
                input_type = SPACE;
            else if(s[i]=='+' || s[i]=='-')
                input_type = SIGNED;
            else if(s[i]=='.')
                input_type = DOT;
            else if(s[i]=='e' || s[i]=='E')
                input_type = EXP;
            else if(isdigit(s[i]))
                input_type = DIGIT;
                
            state = state_table[state][input_type];  
            if(state == -1)
                return false;
        }
        return state == 1 || state == 8 || state == 4 || state == 7;
    }
};
