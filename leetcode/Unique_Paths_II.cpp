class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int table[100][100];
        unsigned i,j;
        for(i=0;i<obstacleGrid.size();i++){
            for(j=0;j<obstacleGrid[0].size();j++){
                if(obstacleGrid[i][j]==1){
                    table[i][j]=0;
                }else{
                    if(i==0 && j==0)
                        table[i][j] =1;
                    else if(i==0)
                        table[i][j] = table[i][j-1];
                    else if(j==0)
                        table[i][j] = table[i-1][j];
                    else{
                        table[i][j] = table[i-1][j]+table[i][j-1];
                    }
                }
            }
        }
        return table[i-1][j-1];
    }
};
