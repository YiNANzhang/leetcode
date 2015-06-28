class Solution {
public:
    vector<int> findSubstring(string S, vector<string>& words) {
        vector<int> res;

	    if (words.empty() || words.size()*words[0].size()>S.length())
	        return res;

	    int lens = S.length();             
	    int lenw = words.size();    
	    int wordLen = words[0].size();         

	   
	    unordered_map<string, int> dict;
	    dict.reserve(lenw);
	    vector<int> toBeFound(lenw + 1, 0);         
	    for (int i = 0; i < lenw; ++i) {
	        if (dict[words[i]] == 0)
	            dict[words[i]] = i + 1;
	        toBeFound[dict[words[i]]]++;
	    }

	    vector<int> curIdArray;
	    curIdArray.reserve(lens / wordLen);

	    for (int startPos = 0; startPos < wordLen; startPos++) {
	        curIdArray.clear();
	    
	        for (int i = startPos; i + wordLen <= lens; i += wordLen) {
	            auto di = dict.find(S.substr(i, wordLen));
	            if (di != dict.end())
	                curIdArray.push_back(di->second);   
	            else
	                curIdArray.push_back(-1);           
	        }


	        vector<int> hasFound(lenw + 1, 0);
	        int err = lenw;
	        for (int i = 0; i < lenw - 1; i++) {
	            int id = curIdArray[i];
	            if (id > 0) {
	                err -= abs(hasFound[id] - toBeFound[id]);
	                err += abs(hasFound[id] + 1 - toBeFound[id]);
	                hasFound[id]++;
	            }
	        }

	        for (int i = 0; i + lenw <= curIdArray.size(); i++) {
	            int id = curIdArray[i + lenw - 1];
	            if (id > 0) {
	                err -= abs(hasFound[id] - toBeFound[id]);
	                err += abs(hasFound[id] + 1 - toBeFound[id]);
	                hasFound[id]++;
	            }

	            if (err == 0)
	                res.push_back(startPos + i*wordLen);

	            id = curIdArray[i];
	            if (id > 0) {
	                err -= abs(hasFound[id] - toBeFound[id]);
	                err += abs(hasFound[id] - 1 - toBeFound[id]);
	                hasFound[id]--;
	            }
	        }
	    }
	    return res;
    }
};
