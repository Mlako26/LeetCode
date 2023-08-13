class Solution {
public:
    int solve(vector<vector<int>>& grid, vector<vector<int>>& mem, int i, int j) {
        if (mem[i][j] != -1) return mem[i][j];
        if (i == grid.size()-1 && j == grid[0].size()-1 && !grid[i][j]) return 1;
        
        int res = 0;
        if (i + 1 < grid.size() && !grid[i+1][j]) res += solve(grid, mem, i+1, j);
        if (j + 1 < grid[0].size() && !grid[i][j+1]) res += solve(grid, mem, i, j+1);
        return mem[i][j] = res;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0]) return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> mem(m, vector<int>(n, -1));
        return solve(obstacleGrid, mem, 0, 0);
    }
};