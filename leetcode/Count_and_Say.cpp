class Solution {
public:
    string countAndSay(int n) {
        string  str;
        if(n==1) return "1";
        if(n>1) str=countAndSay(n-1);
        
        string result;
        int count=1;
        char c;
        for(int i=0;i<str.size()-1;i++){
            if(str[i]!=str[i+1]){
                c = count+'0';
                result += c;
                count = 1;
            }
            else{
                count++;
                continue;
            }
            result += str[i];
        }
        c = count + '0';
        result += c;
        result += str[str.size()-1];
        return result;
    }
};
