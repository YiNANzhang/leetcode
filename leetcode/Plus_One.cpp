class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        //int digit;
        int carry=1;
        
        for(std::vector<int>::reverse_iterator it=digits.rbegin();it!=digits.rend();it++){
            *it+=carry;
            carry = *it/10;
            *it = *it%10;
        }
        if(carry>0){
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};
