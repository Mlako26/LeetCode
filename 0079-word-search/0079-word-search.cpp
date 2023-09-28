class Solution {
public:
    bool findWord(vector<vector<char>>& board, string& word, int i, int j, int idx) {
        if (idx == word.size()) return true;

        int n = board.size(), m = board[0].size();
        bool res = false;

        char prev = board[i][j];
        board[i][j] = '0';

        if (!res && j + 1 < m && board[i][j+1] == word[idx] && board[i][j+1] != '0') res |= findWord(board, word, i, j+1, idx+1);    
        if (!res && j - 1 >= 0 && board[i][j-1] == word[idx] && board[i][j-1] != '0') res |= findWord(board, word, i, j-1, idx+1);    
        if (!res && i + 1 < n && board[i+1][j] == word[idx] && board[i+1][j] != '0') res |= findWord(board, word, i+1, j, idx+1);    
        if (!res && i - 1 >= 0 && board[i-1][j] == word[idx] && board[i-1][j] != '0') res |= findWord(board, word, i-1, j, idx+1);

        board[i][j] = prev;
        return res;    
    }

    bool exist(vector<vector<char>>& board, string word) {
        bool res = false;

        for (int i = 0; i < board.size() && !res; i++) {
            for (int j = 0; j < board[0].size() && !res; j++) {
                vector<vector<char>> aux = board;
                if (board[i][j] == word[0]) res = res || findWord(aux, word, i, j, 1);
            }
        }

        return res;
    }
};