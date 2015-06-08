class Solution {
public:
    int uniquePaths(int m, int n) {
        int table[100][100];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0){
                    table[i][j]=1;
                }else{
                    table[i][j] = table[i-1][j]+table[i][j-1];   
                }
            }
        }
        return table[m-1][n-1];
    }
};
