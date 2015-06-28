class Solution {
public:
    string convertToTitle(int n) {
        string s;
        int quotient;
        int remainder;
        quotient = (n-1)/26;
        remainder = (n-1)%26;
        while(quotient){
            s.insert(s.begin(),'A'+remainder);
            remainder = (quotient-1)%26;
            quotient=(quotient-1)/26;
        }
        s.insert(s.begin(),'A'+remainder);
        return s;
    }
};
