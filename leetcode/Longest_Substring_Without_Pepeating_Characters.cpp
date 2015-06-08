class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        int length=1;
        
        const int MAX_ASICC = 256;
        int expected[MAX_ASICC];
        fill(expected, expected+MAX_ASICC, 0);
        for(int end=0,start=0;end<s.size();end++){
            expected[s[end]]++;
            if(expected[s[end]]>1){
                while(expected[s[start]]<=1){
                    expected[s[start]]--;
                    start++;
                }
                length = length<(end-start)?(end-start):length;
                start++;
                expected[s[end]]--;
            }else{
                length = length<(end-start+1)?(end-start+1):length;
            }
        }
        return length;
    }
};
