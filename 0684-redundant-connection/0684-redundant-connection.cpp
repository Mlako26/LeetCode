class Solution {
public:

vector<bool> visited;
vector<int> p, h;
set<vector<int>> c;

void dfs(vector<vector<int>>& g, int i) {
    visited[i] = true;
    for (auto j : g[i]) {
        if (c.size()) return;
        if (!visited[j]) {
            p[j] = i;
            h[j] = h[i] + 1;
            dfs(g, j);
        } else if (p[i] != j) {
            int it1 = i;
            int it2 = j;
            c.insert({it1,it2});
            while (it1 != it2) {
                if (h[it1] > h[it2]) {
                    c.insert({it1, p[it1]});
                    it1 = p[it1];
                } else {
                    c.insert({it2, p[it2]});
                    it2 = p[it2];
                }
            }
        }
    }
}

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    vector<vector<int>> g(n);
    visited.resize(n, false);
    p.resize(n, -1); h.resize(n, -1);
    h[0] = 0;
    for (auto v : edges) {
        g[v[0] - 1].push_back(v[1] - 1);
        g[v[1] - 1].push_back(v[0] - 1);
    }

    dfs(g,0);

    for (int i = n - 1; i >= 0; i--) {
        int x = edges[i][0] - 1, y = edges[i][1] - 1;
        if (c.count({x,y}) || c.count({y,x})) return edges[i];
    }
    return edges[0];
}
};