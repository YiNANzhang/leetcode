class Solution {
public:
    int compareVersion(string version1, string version2) {
        size_t end1 = version1.find_first_of('.');
        string str1 = version1.substr(0, end1);
        size_t end2 = version2.find_first_of('.');
        string str2 = version2.substr(0, end2);
		size_t begin1 = end1, begin2 = end2;
		
        while(!str1.empty() && !str2.empty()) {
			int cmp1 = stoi(str1, nullptr);
			int cmp2 = stoi(str2, nullptr);
			if(cmp1 < cmp2) return -1;
            else if(cmp1 > cmp2) return 1;
            else {
                str1.clear();str2.clear();
				if(begin1 == string::npos && begin2 == string::npos)
					return 0;
				if(begin1 == string::npos) {
				    end2 = version2.find_first_of('.', begin2 + 1);
				    str2 = version2.substr(begin2 + 1, end2 - begin2 );    
				    break;
				} else if(begin2 == string::npos) {
                    end1 = version1.find_first_of('.', begin1 + 1);
                    str1 = version1.substr(begin1 + 1, end1 - begin1 );
                    break;
				}
                end1 = version1.find_first_of('.', begin1 + 1);
                end2 = version2.find_first_of('.', begin2 + 1);
                str1 = version1.substr(begin1 + 1, end1 - begin1 );
                str2 = version2.substr(begin2 + 1, end2 - begin2 );
				begin1 = end1; begin2 = end2;
            }
        }
        if(str1.empty() && str2.empty()) return 0;
        if(str1.empty()) {
			while(!str2.empty()) {
				if(stoi(str2, nullptr) == 0) {
					if(end2 == string::npos)
						return 0;
				    end2 = version2.find_first_of('.', begin2 + 1);
					str2 = version2.substr(begin2 + 1, end2 - begin2);
					begin2 = end2;
				} else {
					return -1;
				}
			}
			return 0;
	    }else {
			while(!str1.empty()) {
				if(stoi(str1, nullptr) == 0) {
					if(end1 == string::npos)
						return 0;
				end1 = version1.find_first_of('.', begin1 + 1);
				str1 = version1.substr(begin1 + 1, end1 - begin1);
				begin1 = end1;
			    } else {
					return 1;
				}
			}
			return 0;
		}
    }
};
