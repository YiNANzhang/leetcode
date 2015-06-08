class Solution {
public:
    string convert(string s, int nRows) {
        if(nRows == 1) return s;
        string ret;
        for(int i=0;i<nRows;i++){
            int j=i;
			if(j>=s.size())
				break;
			ret+=s[j];
            while(j<s.size()){
                int pre = j;
                j +=(nRows-1-i)*2;
                if(j<s.size() && j!=pre)
                    ret+=s[j];
                pre = j;
                j +=i*2;
                if(j<s.size() && j!=pre)
                    ret+=s[j];
            }
        }
        return ret;
    }
};
