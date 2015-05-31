class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > ret;
        vector<int> array(n);
        
        iota(array.begin(), array.end(), 1);
        
        vector<bool> select(n, false);
        fill_n(select.begin(), k, true);
        do{
            vector<int> line(k);
            for(int i=0, index=0;i<n;i++){
                if(select[i])
                    line[index++] = array[i];
            } 
            ret.push_back(line);
        }while(prev_permutation(select.begin(), select.end()) );
        return ret;
    }
};
