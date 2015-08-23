class Solution {
public:
    int countDigitOne(int n) {
        if (n <= 0) return 0;
        long long digits = 1;
        //int temp = n;
        while (n/(digits*10)) {
            digits *= 10;
        }
        int result = 0;
        //digits == 1 ? 1 : digits/10;
        int re = 0, quo = 0, temp = n;
        while (digits) {
            quo = temp/digits; re = temp % digits;
            if (quo == 1) {
                result += n / (digits*10) * digits;
                result += re + 1;
            } else if (quo == 0) {
                result += n / (digits*10) * digits;
            } else {
                result += ((n/(digits*10))+1) * digits;
            }
            temp = re;
            digits /= 10;
        }
        return result;
    }
};
