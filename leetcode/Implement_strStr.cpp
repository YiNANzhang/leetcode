class Solution {
public:
    int strStr(string haystack, string needle) {
         // write your code here
        int pn = 0, sn = 0;
        
		if (haystack.empty() && needle.empty()) return 0;
		if (haystack.empty()) return -1;

		pn = needle.size();
		sn = haystack.size();
		if(sn < pn) return -1;
		if(pn == 0) return 0;  
		//compute next
		int next[pn];
		next[0] = -1;
		for(int i = 1; i < pn; ++i) {
			int j = next[i-1];
			if(needle[i] == needle[j+1]) next[i] = j+1; 
			else {
				while(j > -1 && needle[i] != needle[j+1]) j = next[j];
				next[i] = j;
			}
		}
		//p = haytack; q = needle;
		int i = 0, j = -1;
		for(i = 0; i < sn && j < pn-1;) {
			if(haystack[i] == needle[j+1]) { ++i;++j;}
			else {
				if(j == -1) ++i;
				while(j > -1 && haystack[i] != needle[j+1]) j = next[j];
			}
		}
		if(j == pn-1) return i - pn;
		return -1;
	}       
};
