class Solution {
public:
    bool possible(vector<pair<int,int>>& pos, int i, int j) {
        for (auto p : pos) {
            if (p.first == i || p.second == j || abs(p.first - i) == abs(p.second - j)) return false;
        }
        return true;
    }

    vector<vector<string>> solve(vector<pair<int,int>> &pos, int n, int q, int i, int j) {
        if (q == n) {
            string empty; empty.resize(n, '.');
            vector<string> res(n, empty);
            for (auto p : pos) res[p.first][p.second] = 'Q';
            return {res};
        }

        vector<vector<string>> ans;
        while (i < n) {
            while (j < n) {
                if (possible(pos, i, j)) {
                    pos.push_back({i,j});
                    vector<vector<string>> aux = solve(pos, n, q+1, i, j);
                    pos.pop_back();
                    for (auto v: aux) ans.push_back(v);
                }
                j++;
            }
            i++;
            j = 0;
        }
        return ans;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<pair<int,int>> pos;
        return solve(pos, n, 0, 0, 0);
    }
};