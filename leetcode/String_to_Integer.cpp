class Solution {
public:
    int atoi(const char *str) {
		int flag = 1;
		int result=0;
		int i=0;
		int length = strlen(str);
		while(str[i] == ' ' && i<length){i++;}
		if(str[i] == '+' || str[i] == '-'){
		    flag = str[i]=='+'?1:-1;
		    i++;
		}
		for(;i<length;i++){
		    if(str[i]<'0' || str[i]>'9')
		        break;
		    if(result > INT_MAX/10 || (result == INT_MAX/10 && (str[i]-'0') > INT_MAX % 10))
		        return result = (flag == 1) ? INT_MAX : INT_MIN;
		    result = result*10+str[i]-'0';
		}
		return result*flag;

	}
};
