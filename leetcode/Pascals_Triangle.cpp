class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> >  vv;
        vector<int> v;
        for(auto i=1;i<=numRows;i++){
            v.clear();
            for(auto j=0;j<i;j++){
                if(j==0 || j== i-1)
                    v.push_back(1);
                else{
                    vector<int> &pre=vv[i-2];
                    int val = pre[j-1] + pre[j];
                    v.push_back(val);
                }
            }
            vv.push_back(v);
        }
        return vv;
    }
};
