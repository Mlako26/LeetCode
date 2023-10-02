class Solution {
public:
   vector<vector<pair<bool,bool>>> visited;
    
   void dfs1(vector<vector<int>>& h, int i, int j) {
        int n = h.size();
        int m = h[0].size();

        visited[i][j].first = true;
        if (j+1 < m && !visited[i][j+1].first && h[i][j] <= h[i][j+1]) dfs1(h,i,j+1);
        if (j-1 >= 0 && !visited[i][j-1].first && h[i][j] <= h[i][j-1]) dfs1(h,i,j-1);
        if (i+1 < n && !visited[i+1][j].first && h[i][j] <= h[i+1][j]) dfs1(h,i+1,j);
        if (i-1 >= 0 && !visited[i-1][j].first && h[i][j] <= h[i-1][j]) dfs1(h,i-1,j);
    }

    void dfs2(vector<vector<int>>& h, int i, int j) {
        int n = h.size();
        int m = h[0].size();

        visited[i][j].second = true;
        if (j+1 < m && !visited[i][j+1].second && h[i][j] <= h[i][j+1]) dfs2(h,i,j+1);
        if (j-1 >= 0 && !visited[i][j-1].second && h[i][j] <= h[i][j-1]) dfs2(h,i,j-1);
        if (i+1 < n && !visited[i+1][j].second && h[i][j] <= h[i+1][j]) dfs2(h,i+1,j);
        if (i-1 >= 0 && !visited[i-1][j].second && h[i][j] <= h[i-1][j]) dfs2(h,i-1,j);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        visited.resize(n, vector<pair<bool,bool>>(m, {false,false}));
        for (int i = 0; i < n; i++) {
            dfs1(heights, i, 0);
        }

        for (int i = 0; i < m; i++) {
            dfs1(heights, 0, i);
        }

        for (int i = 0; i < n; i++) {
            dfs2(heights, i, m-1);
        }

        for (int i = 0; i < m; i++) {
            dfs2(heights, n-1, i);
        }

        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j].first && visited[i][j].second) ans.push_back({i,j});
            }
        }
        return ans;
    }

};