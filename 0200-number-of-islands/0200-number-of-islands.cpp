class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int n = grid.size();
        int m = grid[0].size();
        grid[i][j] = '0';
        if (j + 1 < m && grid[i][j+1] == '1') dfs(grid, i, j+1);
        if (j - 1 >= 0 && grid[i][j-1] == '1') dfs(grid, i, j-1);
        if (i + 1 < n && grid[i+1][j] == '1') dfs(grid, i+1, j);
        if (i - 1 >= 0 && grid[i-1][j] == '1') dfs(grid, i-1, j);
    }

    int numIslands(vector<vector<char>>& grid) {
        int cc = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    cc++;
                }
            }
        }
        return cc;
    }
};