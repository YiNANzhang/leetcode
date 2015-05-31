class Solution {
struct map{
	int base;
	string encode;
};
string result;
public:
    string intToRoman(int num) {
 		map inttr[]={
			{1,"I"},
			{4,"IV"},
			{5,"V"},
			{9,"IX"},
			{10,"X"},
			{40,"XL"},
			{50,"L"},
			{90,"XC"},
			{100,"C"},
			{400,"CD"},
			{500,"D"},
			{900,"CM"},
			{1000,"M"}
         };
		int div;
		int remainder = num;
		for(int i=13;i>0;i--){
			div = remainder/inttr[i-1].base;
			remainder = remainder % inttr[i-1].base;
			if(div == 0)
				continue;
			for(int j=div;j>0;j--){
				result.append(inttr[i-1].encode);
			}
		}
		return result;       
    }
};
