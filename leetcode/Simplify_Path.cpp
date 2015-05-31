class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stck;
        size_t found_s = path.find_first_of("/");
        size_t found_e = path.find_first_of("/", found_s + 1);
        while(found_e != std::string::npos) {
            string dir = path.substr(found_s+1, found_e - found_s - 1);
            if(!dir.empty() && dir != ".") {
                if(dir == "..") {
                    if(!stck.empty())
                        stck.pop_back();
                }else{
                    stck.push_back(dir);
                }
            }
            found_s = found_e;
            found_e = path.find_first_of("/", found_s + 1);
        }
        if(!path.substr(found_s + 1).empty()) stck.push_back(path.substr(found_s + 1));
        string ret;
        if(stck.empty()) return "/";
        for(auto i : stck) {
            ret += "/";
            ret += i;
        }
        return ret;
        //while(!path.substr(found_s+1, found_e-found_s).empty()) {
        //    found_s = foutd_e;
        //}
    }
};
