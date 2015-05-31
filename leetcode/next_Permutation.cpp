class Solution {
public:
    void nextPermutation(vector<int> &num) {
        vector<int>::reverse_iterator rlast = num.rend();
        vector<int>::reverse_iterator rit = num.rbegin();
        while(rit!=rlast){
            if(*rit > *(++rit))
                break;
        }
        if(rit == rlast){
            reverse(num.begin(), num.end());
            return;
        }
        vector<int>::reverse_iterator change = find_if(num.rbegin(), rit, bind1st(less<int>(), *rit));
        swap(*rit, *change);
        reverse(num.rbegin(), rit);
        return;
    }
};
