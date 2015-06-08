class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
		int q,r;
		int d=1;
		while(x/d>=10) d*=10;
		while(d>0){
			q=x/d;
			r=x%10;
			if(q!=r) return false;
			x=x%d/10;
			d=d/100;
		}
		return true;
    }
};
