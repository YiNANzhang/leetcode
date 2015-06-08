class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        //if(n1==0 || n2==0) return n1==0?n2:n1;
        int table[n1+1][n2+1];
        //fill(table, table+n1*n2, INT_MAX);
        //table[0][0]=0;
        for(int i=0;i<=n1;i++){
            table[i][0] = i;
        }
        for(int i=0;i<=n2;i++){
            table[0][i] = i;
        }
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(word1[i-1] == word2[j-1]) table[i][j] = table[i-1][j-1];
                else{
                    table[i][j] = min(table[i][j-1], min(table[i-1][j-1], table[i-1][j]) )+1;
                }
            }
        }
        return table[n1][n2];
    }
};
