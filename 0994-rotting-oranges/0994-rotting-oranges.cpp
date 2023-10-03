class Solution {
public:

    vector<vector<int>> visited;

    void dfs(vector<vector<int>>& g, int i, int j, int t) {
        int n = g.size();
        int m = g[0].size();
        visited[i][j] = t++;
        if (j+1 < m && g[i][j+1] == 1 && visited[i][j+1] > t) dfs(g,i,j+1,t);
        if (j-1 >= 0 && g[i][j-1] == 1 && visited[i][j-1] > t) dfs(g,i,j-1,t);
        if (i+1 < n && g[i+1][j] == 1 && visited[i+1][j] > t) dfs(g,i+1,j,t);
        if (i-1 >= 0 && g[i-1][j] == 1 && visited[i-1][j] > t) dfs(g,i-1,j,t);
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        visited.resize(n, vector<int>(m, INT_MAX));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) dfs(grid, i, j, 0);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j] < INT_MAX) ans = max(ans, visited[i][j]);
                else if(grid[i][j] == 1) return -1;
            }
        }
        return ans;
    }

};