class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j) {
        int n = grid.size();
        int m = grid[0].size();
        grid[i][j] = 0;
        int ans = 1;
        if (j + 1 < m && grid[i][j+1] == 1) ans += dfs(grid, i, j+1);
        if (j - 1 >= 0 && grid[i][j-1] == 1) ans += dfs(grid, i, j-1);
        if (i + 1 < n && grid[i+1][j] == 1) ans += dfs(grid, i+1, j);
        if (i - 1 >= 0 && grid[i-1][j] == 1) ans += dfs(grid, i-1, j);
        return ans;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                   ans = max(ans, dfs(grid, i, j));
                }
            }
        }
        return ans;
    }
};