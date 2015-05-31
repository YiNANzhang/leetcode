class Solution {
public:
    string addBinary(string a, string b) {
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
            sum = (ai+bi+carry) %2 ;
            carry = (ai+bi+carry) / 2;
            result.insert(result.begin(),sum+'0'); 
        }
        if(carry == 1)
            result.insert(result.begin(),'1');
        return result;
    }
};
