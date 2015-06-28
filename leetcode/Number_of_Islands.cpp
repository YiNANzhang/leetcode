class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        if(grid.empty()) return 0;
        int row = grid.size();
        int col = grid[0].size();
        int num_islands = 0;
        //vector<vector<bool> > visited(row, vector<bool>(col, false));
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(grid[i][j] != '0' && grid[i][j] != '#') {
                    dfs(i, j, grid);
                    num_islands++;
                }
            }
        }
        return num_islands;
    }
    
    void dfs(int x, int y,  vector<vector<char> > &grid) {
        //if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() ) return;
        if(grid[x][y] == '0' || grid[x][y] == '#') return;
        grid[x][y] = '#';
        if(x != 0) dfs(x-1, y, grid);
        if(y != 0) dfs(x, y-1, grid);
        if(x != grid.size() - 1) dfs(x+1, y, grid);
        if(y != grid[0].size() -1) dfs(x, y+1, grid);
    }
};
