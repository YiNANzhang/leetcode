class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > ret;
        int size_n = S.size();
        sort(S.begin(), S.end());
        bool select[size_n];
        fill(select, select+size_n, false);
        int i=0;
        vector<int> empty;
        ret.push_back(empty);
        while(i<size_n){
            select[i] = true;
            do{
                vector<int> tmp;
                for(int j=0;j<size_n;j++)
                    if(select[j])
                        tmp.push_back(S[j]);
                ret.push_back(tmp);
            }while(prev_permutation(select, select+size_n));
            i++;
        }
        return ret;
    }
};
