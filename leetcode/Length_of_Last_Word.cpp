class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int length = 0;
        int i=0;
        if(*s==0)
            return 0;
        if(s[0]!=' '){
            length++;
        }
        i++;
        while(s[i]){
            if(s[i]==' '){}
            else{
                if(s[i-1]==' ')
                    length=0;
                length++;
            }
            i++;
        }
        return length;
    }
};
