class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ret;

		int l = 0, j, i; //record the num per line.
		for(i = 0, j = 0; i < words.size(); ++i, ++j, ++l) {
			l += words[i].size();
		}
			string line;
			if(l <= maxWidth) {
				//++j;
				continue;
			}
			if(j == 1) {
			    line = words[i-1];
			    if(line.size() < maxWidth) line.append(maxWidth-line.size(), ' ');
				ret.push_back(line);
			} else {

				l -= words[i].size();
				int diff = maxWidth - l + 1;
				int quo = diff / (j-1);
				int re = diff % (j-1);
				for (int k = i-j; k < i-j+re; ++k) {
					line += words[k];
					line.append(quo+2, ' ');
				}	
				for(int k = i - j + re; k < i-1; ++k) {
					line += words[k];
					line.append(quo+1, ' ');
				}
				line += words[i-1];	
				if(line.size() < maxWidth) line.append(maxWidth-line.size(), ' ');
				ret.push_back(line);
			}
			j = 0;
			l = words[i].size();
		}
		
	
		string line;
		for(int k = i-j; k < words.size()-1; ++k) {
			line += words[k];
			line += ' ';
		}
		line += words[i-1];	
		if(line.size() < maxWidth) line.append(maxWidth-line.size(), ' ');
		ret.push_back(line);
		return ret;
    }
};

