class Solution {
public:
    string minWindow(string S, string T) {
        if(S.size()==0)  return "";
        if(S.size()<T.size()) return "";
        int minWidth = INT_MAX;
        
        int MAXASICC = 256;
        int expect[MAXASICC];
        int rearch[MAXASICC];
        fill(expect, expect+MAXASICC, 0);
        fill(rearch, rearch+MAXASICC, 0);
        
        for(int i=0;i<T.size();i++) expect[T[i]]++;
        
        int winstart = 0;
        int appear = 0;
        int minstart = 0;
        for(int winend=0;winend<S.size();winend++){
            
            rearch[S[winend]]++;
            if(rearch[S[winend]]<=expect[S[winend]]){
                appear++;
            }
            
            if(appear == T.size() && expect[S[winend]]>0){
                while(expect[S[winstart]]==0 || rearch[S[winstart]] > expect[S[winstart]]){
                    rearch[S[winstart]]--;
                    winstart++;
                }
                if(minWidth>(winend-winstart+1)){
                    minWidth = winend - winstart+1;
                    minstart = winstart;
                }
            }
        }
        if(minWidth == INT_MAX) return "";
        return S.substr(minstart, minWidth);
    }
};
