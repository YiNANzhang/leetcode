class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(denominator == 0) return "";
        if(numerator == 0) return "0";
        long num = numerator;
        long den = denominator;
        num = abs(num); den = abs(den);
        string result;
        vector<int> vctr;
        long quo = num/den;
        long ram = num%den;
        string c;
        string str;
        if((numerator<0)^(denominator<0)){
            result.append("-");
        }
        while(quo/10!=0){
            c = quo%10 + '0';
            quo = quo/10;
            str.append(c);
        }
        c = quo+'0';
        str.append(c);
        reverse(str.begin(),str.end());
        result.append(str);
        if(ram != 0)
            result.append(".");
        int index = result.size();
        while(ram!=0){
            vctr.push_back(ram);
            ram *=10;
            quo = ram/den;
            ram = ram%den;
            c = quo + '0';
            result.append(c);
            for(unsigned i=0;i<vctr.size();i++){
                if(ram==vctr[i]){
                    result.insert(index+i,"(");
                    result.append(")");
                    return result;
                }
            }
        }
        return result;
    }
};
