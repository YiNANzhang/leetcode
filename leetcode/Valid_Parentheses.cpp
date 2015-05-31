class Solution {
public:
    bool isPalindrome(string s) {
        size_t head,tail,n;
        head = 0;
        tail = s.size()-1;
        while(!(head == tail || head-tail==1)){
            if(!((toLittle(s[head])<='z' && toLittle(s[head])>='a') || (s[head]>='0' && s[head]<='9'))) {
                head++;
                continue;
            }
            if(!((toLittle(s[tail])<='z' && toLittle(s[tail])>='a') || (s[tail]>='0' && s[tail]<='9'))){
                tail--;
                continue;
            }
            if(toLittle(s[head]) != toLittle(s[tail]))
                return false;
            head++;tail--;
        }
        return true;
    }
    
    char toLittle(char &c){
        if(c>='A' && c<='Z')
            return c+32;
        return c;
    }
};
