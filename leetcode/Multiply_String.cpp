class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        //string ret;
        int n1 = num1.size();
        int n2 = num2.size();
        vector<string> str(n2);
        for (int i = n2-1; i >= 0; --i) {
            int c = 0;
            str[i].append(n2-i-1, '0');
            for (int j = n1-1; j >= 0; --j) {
                int q = ((num1[j] - '0') * (num2[i] - '0') + c) % 10;
                str[i] += (q + '0');
                c = ((num1[j] - '0') * (num2[i] - '0') + c) / 10;
            }
            if(c > 0) str[i] += (c + '0');
            reverse(str[i].begin(), str[i].end());
        }
        
        for (int i = n2-2; i >= 0; --i) {
            str[i] = addString(str[i], str[i+1]);
        }
        //reverse(str[0].begin(), str[0].end());
		return str[0];
    }
    
    string addString(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        string::size_type n = a.size()>b.size() ? a.size():b.size();
        string::size_type i;
        string result;
        char ai,bi;
        char sum = 0;
        char carry = 0;
        for(i=0;i<n;i++){
            ai = i<a.size()?(a[i]-'0'):0;
            bi = i<b.size()?(b[i]-'0'):0;
            sum = (ai+bi+carry) % 10 ;
            carry = (ai+bi+carry) / 10;
            result.insert(result.begin(),sum+'0'); 
        }
        if(carry > 0)
            result.insert(result.begin(), carry+'0');
        return result;
    }
};
