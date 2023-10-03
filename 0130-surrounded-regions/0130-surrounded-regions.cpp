class Solution {
public:

    vector<vector<bool>> visited;

    void dfs(vector<vector<char>>& b, int i, int j) {
        int n = b.size();
        int m = b[0].size();
        visited[i][j] = true;

        if (j+1 < m && !visited[i][j+1] && 'O' == b[i][j+1]) dfs(b,i,j+1);
        if (j-1 >= 0 && !visited[i][j-1] && 'O' == b[i][j-1]) dfs(b,i,j-1);
        if (i+1 < n && !visited[i+1][j] && 'O' == b[i+1][j]) dfs(b,i+1,j);
        if (i-1 >= 0 && !visited[i-1][j] && 'O' == b[i-1][j]) dfs(b,i-1,j);
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        visited.resize(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') dfs(board, i, 0);
            if (board[i][m-1] == 'O') dfs(board, i, m-1);
        }

        for (int i = 0; i < m; i++) {
            if (board[0][i] == 'O') dfs(board, 0, i);
            if (board[n-1][i] == 'O') dfs(board, n-1, i);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j]) board[i][j] = 'X';
            }
        }
    }
};