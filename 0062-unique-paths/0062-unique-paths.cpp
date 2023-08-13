class Solution {
public:
    int solve(vector<vector<int>>& mem, int i, int j) {
        if (mem[i][j] != -1) return mem[i][j];
        if (i == mem.size() - 1 || j == mem[0].size() - 1) return 1;

        int res = 0;

        if (i + 1 < mem.size()) res += solve(mem, i+1, j); // Go down
        if (j + 1 < mem[0].size()) res += solve(mem, i, j+1); // Go right 

        return mem[i][j] = res;
    }

    int uniquePaths(int m, int n) {
        // To get from the top-left to the bottom-right corner, 
        // you need to go down m-1 times and right n-1 times.
        // Therefore, on each step you can either go down or right.
        vector<vector<int>> mem(m, vector<int>(n, -1));
        return solve(mem, 0, 0);
    }
};