class Solution {
public:
    int solve(vector<vector<int>>& grid, vector<vector<int>>& mem, int i, int j) {
        if (mem[i][j] != -1) return mem[i][j];
        if (i == grid.size()-1 && j == grid[0].size()-1) return grid[i][j];
        
        int res = INT_MAX;
        if (i + 1 < grid.size()) res = grid[i][j] + solve(grid, mem, i+1, j);
        if (j + 1 < grid[0].size()) res = min(res, grid[i][j] + solve(grid, mem, i, j+1));
        return mem[i][j] = res;
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> mem(grid.size(), vector<int>(grid[0].size(), -1));
        return solve(grid, mem, 0, 0);        
    }
};